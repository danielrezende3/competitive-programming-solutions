applicants, apartments, allowed_difference = [int(x) for x in input().split()]

applicants_list = sorted(map(int, input().split()))
apartments_list = sorted(map(int, input().split()))

ans = 0
i = 0
j = 0

while i < len(applicants_list) and j < len(apartments_list):
    if abs(applicants_list[i] - apartments_list[j]) <= allowed_difference:
        ans += 1
        i += 1
        j += 1
    elif applicants_list[i] < apartments_list[j]:
        i += 1
    else:
        j += 1

print(ans)
