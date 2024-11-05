def line_intersection(line1, line2) -> bool:
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1])

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    return False if div == 0 else True


A = (0, 0)
B = (3, 7)
line1 = (A, B)
C = (10, 0)
D = (4, 7)
line2 = (C, D)
print(type(line1))
print(line_intersection(line1, line2))
