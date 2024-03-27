n, m = map(int, input().split())
num = 0
lst1 = [input() for _ in range(n)]
lst2 = [input() for _ in range(m)]
for i in lst2:
    if i in lst1:
        num += 1
print(num)
