def total_sum(n):
    return n * (n + 1) // 2


def two_sets(n):
    if total_sum(n) % 2 == 0:
        print("YES")
        list1 = []
        list2 = []

        if n % 2 == 0:
            for i in range(1, n + 1):
                if i % 4 == 0 or i % 4 == 1:
                    list1.append(i)
                else:
                    list2.append(i)
        else:
            for i in range(1, n + 1):
                if i % 4 == 3 or i % 4 == 0:
                    list1.append(i)
                else:
                    list2.append(i)
        print(f"{len(list1)}")
        print(*list1)
        print(f"{len(list2)}")
        print(*list2)
    else:
        print("NO")

n = int(input())
two_sets(n)
