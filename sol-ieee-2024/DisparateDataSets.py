import numpy as np
import scipy

code_digit = -1


def process_events(lines: list) -> list:
    parent_index = -1
    child_index = -1
    for index, line in enumerate(lines):
        line = line.split(",")
        is_parent = True if line[5] == '"Parent Event"' else False
        is_child = True if line[5] == '"IEEE Event"' else False
        if is_parent:
            parent_index = index
        if is_child:
            child_index = index

    if parent_index >= 0 and child_index == -1:
        del lines[parent_index]
    if child_index >=0 and parent_index == -1:
        del lines[child_index]

    return lines


# lines = []
# while True:
#     try:
#         line = input()
#         if line:
#             lines.append(line)
#         else:
#             break
#     except EOFError:
#         break


def test_process_events():
    # Test case: Parent without children (should be excluded)
    records = [
        'EVT020,"International Symposium on AI","ISAI",,"","Parent Event"',
    ]
    expected_output = []
    response_output = process_events(records)
    assert (
        response_output == expected_output
    ), "Parent without children (should be excluded) failed"

    # Test case: child without parent (should be excluded)
    records = [
        'EVT020,"International Symposium on AI","ISAI",,"","IEEE Event"',
    ]
    expected_output = []
    response_output = process_events(records)
    assert (
        response_output == expected_output
    ), "child without parent (should be excluded) failed"

    # Test case: Parent with children having the same 3 Digit Project Code
    records = [
        '"EVT001","International Conference on Robotics","ICR",,"","Parent Event"',
        '"EVT002","International Conference on Robotics 2021","ICR","PC001","001","IEEE Event"',
        '"EVT003","International Conference on Robotics 2022","ICR","PC001","001","IEEE Event"',
    ]
    expected_output = [
        '"EVT001","International Conference on Robotics","ICR",,"001","Parent Event"',
        'EVT002,"International Conference on Robotics 2021","ICR","PC001","001","IEEE Event","EVT001"',
        'EVT003,"International Conference on Robotics 2022","ICR","PC001","001","IEEE Event","EVT001"',
    ]
    response_output = process_events(records)
    assert (
        response_output == expected_output
    ), "Parent with children having the same 3 Digit Project Code failed"

    # Test case: Parent with children having different 3 Digit Project Codes
    records = [
        'EVT010,"Data Science Summit","DSS",,"","Parent Event"',
        'EVT011,"Data Science Summit 2021","DSS","DSA123","123","IEEE Event"',
        'EVT012,"Data Science Summit 2022","DSS","DSB456","456","IEEE Event"',
    ]
    expected_output = [
        'EVT010,"Data Science Summit","DSS",,"???","Parent Event"',
        'EVT011,"Data Science Summit 2021","DSS","DSA123","123","IEEE Event",EVT010',
        'EVT012,"Data Science Summit 2022","DSS","DSB456","456","IEEE Event",EVT010',
    ]
    response_output = process_events(records)
    assert (
        response_output == expected_output
    ), "Parent with children having different 3 Digit Project Codes failed"

    # Test case: Serialized set with multiple parents (should be excluded)
    records = [
        'EVT030,"Quantum Computing Conference","QCC",,"","Parent Event"',
        'EVT031,"Quantum Computing Conference","QCC",,"","Parent Event"',
        'EVT032,"Quantum Computing Conference 2021","QCC","QC001","001","IEEE Event"',
    ]
    expected_output = []
    response_output = process_events(records)
    assert response_output == expected_output, "Test case 4 failed"

    # Test case: Event without acronym (should be excluded)
    records = [
        'EVT040,"Cybersecurity Forum","","CSF123","123","IEEE Event"',
    ]
    expected_output = []
    assert process_events(records) == expected_output, "Test case 5 failed"

    # Test case: Child event without a parent (should be excluded)
    records = [
        'EVT050,"Blockchain Expo 2021","BCE","BCX789","789","IEEE Event"',
    ]
    expected_output = []
    assert process_events(records) == expected_output, "Test case 6 failed"

    # Test case: Mixed valid and invalid records
    records = [
        'EVT060,"Neural Networks Conference","NNC",,"","Parent Event"',  # Valid parent
        'EVT061,"Neural Networks Conference 2021","NNC","NN001","001","IEEE Event"',  # Valid child
        'EVT070,"Artificial Intelligence Summit","","AI123","123","IEEE Event"',  # Invalid (no acronym)
        'EVT080,"Machine Learning Conference","MLC",,"","Parent Event"',  # Invalid parent (no children)
        'EVT090,"Data Analytics Forum 2021","DAF","DA456","456","IEEE Event"',  # Invalid child (no parent)
    ]
    expected_output = [
        'EVT060,"Neural Networks Conference","NNC",,"001","Parent Event"',
        'EVT061,"Neural Networks Conference 2021","NNC","NN001","001","IEEE Event"',
    ]
    assert process_events(records) == expected_output, "Test case 7 failed"

    # Test case: Parent with children, but children have no 3 Digit Project Code
    records = [
        'EVT100,"Cloud Computing Conference","CCC",,"","Parent Event"',
        'EVT101,"Cloud Computing Conference 2021","CCC","CCX","","IEEE Event"',
        'EVT102,"Cloud Computing Conference 2022","CCC","CCY","","IEEE Event"',
    ]
    expected_output = [
        'EVT100,"Cloud Computing Conference","CCC",,"???","Parent Event"',
        'EVT101,"Cloud Computing Conference 2021","CCC","CCX","","IEEE Event"',
        'EVT102,"Cloud Computing Conference 2022","CCC","CCY","","IEEE Event"',
    ]
    assert process_events(records) == expected_output, "Test case 8 failed"

    # Test case: Acronyms with different cases
    records = [
        'EVT110,"Internet of Things Conference","IoTC",,"","Parent Event"',
        'EVT111,"Internet of Things Conference 2021","IOTC","ITC001","001","IEEE Event"',
        'EVT112,"Internet of Things Conference 2022","IoTc","ITC002","002","IEEE Event"',
    ]
    expected_output = []
    assert process_events(records) == expected_output, "Test case 9 failed"

    # Test case: Parent with one child
    records0 = [
        'EVT120,"Bioinformatics Symposium","BIS",,"","Parent Event"',
        'EVT121,"Bioinformatics Symposium 2021","BIS","BI001","001","IEEE Event"',
    ]
    expected_output0 = [
        'EVT120,"Bioinformatics Symposium","BIS",,"001","Parent Event"',
        'EVT121,"Bioinformatics Symposium 2021","BIS","BI001","001","IEEE Event"',
    ]
    assert process_events(records0) == expected_output0, "Test case 10 failed"

    print("All test cases passed!")


# Run the test function
test_process_events()
