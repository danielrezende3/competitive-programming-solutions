# Read input
test = str(input())
teste = list(test)
previous = teste[0]
biggest = 0
count = 0
for i in teste:
    if i == previous:
        count += 1
    else:
        previous = i
        count = 1

    if count > biggest:
        biggest = count

print(biggest)