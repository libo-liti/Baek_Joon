n = int(input())
lst = list(map(int, input().split()))
lst.sort()
result = 0
for i in range(n):
    result += lst[i] * (n - i)

print(result)
