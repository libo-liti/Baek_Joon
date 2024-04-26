num = 123456 * 2 + 1
lst = [1] * num

for i in range(2, num):
    for j in range(2, int(i**0.5) + 1):
        if i % j == 0:
            lst[i] = 0
            break

while True:
    n = int(input())
    if n == 0:
        break
    print(sum(lst[n + 1: n * 2 + 1]))
