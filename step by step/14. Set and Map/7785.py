import sys
input = sys.stdin.readline

n = int(input())
lst = []
lst = set(lst)
for i in range(n):
    a = (input().split())[0]
    if a in lst:
        lst.remove(a)
    else:
        lst.add(a)
lst = list(lst)
lst.sort(reverse=True)
[print(i) for i in lst]
