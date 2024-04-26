n = int(input())
lst = [list(input().split()) for _ in range(n)]
lst.sort(key=lambda x: int(x[0]))
[print(*lst[i]) for i in range(n)]
