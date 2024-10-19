def zeros_matrix(n):
    return [[0 for _ in range(n)] for _ in range(n)]


def sum_of_possibilities(array, n):
    sum = 0
    for i in range(0, n):
        for j in range(0, n):
            if array[i][j] != 0:
                sum += array[i][j]

    return sum


def array_of_possibilities(n):
    array = zeros_matrix(n)

    for i in range(0, n):
        for j in range(0, n):
            if i + 2 < n and j + 1 < n:
                array[i + 2][j + 1] += 1
            if i + 2 < n and j - 1 >= 0:
                array[i + 2][j - 1] += 1
            if i - 2 >= 0 and j - 1 >= 0:
                array[i - 2][j - 1] += 1
            if i - 2 >= 0 and j + 1 < n:
                array[i - 2][j + 1] += 1
            # one line and two columns
            if i + 1 < n and j + 2 < n:
                array[i + 1][j + 2] += 1
            if i + 1 < n and j - 2 >= 0:
                array[i + 1][j - 2] += 1
            if i - 1 >= 0 and j - 2 >= 0:
                array[i - 1][j - 2] += 1
            if i - 1 >= 0 and j + 2 < n:
                array[i - 1][j + 2] += 1

    return array


def total_ilegal_moves(n):
    freq_2 = 4
    freq_3 = 8
    freq_4 = 12 + 4 * (n - 6)
    freq_6 = 8 + 4 * (n - 6)
    freq_8 = pow(n - 4, 2)
    sum = freq_2 * 2 + freq_3 * 3 + freq_4 * 4 + freq_6 * 6 + freq_8 * 8
    return sum


def frequency_of_elements(matrix):
    frequency = {2: 0, 3: 0, 4: 0, 6: 0, 8: 0}

    for row in matrix:
        for element in row:
            frequency[element] += 1

    return frequency


def print_matrix(matrix):
    for row in matrix:
        print(row)

# dividir sum/2 pela repeticao de cada elemento
n = int(input())
for interation in range(1, n + 1):
    total_positions = interation * interation
    possible_positions = total_positions * (total_positions - 1) / 2

    if interation < 6:
        sum = sum_of_possibilities(interation)
        ans = possible_positions - (sum / 2)
    else:
        ans = possible_positions - total_ilegal_moves(interation) / 2

    print(int(ans))
