n, m = map(int, input().split())
set1 = {input() for _ in range(n)}
set2 = {input() for _ in range(m)}

lst = sorted(list(set1.intersection(set2)))
print(len(lst))
[print(i) for i in lst]
