n = int(input())
result = 0
for i in range(1, n + 1):
    num = i + sum(map(int, str(i)))

    if num == n:
        result = i
        break
print(result)
