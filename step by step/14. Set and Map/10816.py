import collections

n = int(input())
lst1 = list(map(int, input().split()))
m = int(input())
lst2 = list(map(int, input().split()))

lst1 = collections.Counter(lst1)

for i in lst2:
    print(lst1[i], end=' ')
