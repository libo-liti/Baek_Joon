n = int(input())
lst = [input() for _ in range(n)]
lst = set(lst)
lst = list(lst)
lst.sort(key=lambda x: (len(x), x))
[print(lst[i]) for i in range(len(lst))]
