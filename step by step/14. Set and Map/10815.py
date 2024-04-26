n = int(input())
lst1 = set(map(int, input().split()))
m = int(input())
lst2 = list(map(int, input().split()))

for i in range(m):
    if (lst2[i] in lst1):
        lst2[i] = 1
    else:
        lst2[i] = 0
print(*lst2)
