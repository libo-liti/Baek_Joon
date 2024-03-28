n, m = map(int, input().split())
dic = {}
redic = {}
lst = []
for i in range(n):
    a = input()
    dic[str(i+1)] = a
    redic[a] = str(i + 1)
for _ in range(m):
    a = input()
    if (a in dic):
        lst.append(dic[a])
    elif (a in redic):
        lst.append(redic[a])
[print(lst[i]) for i in range(len(lst))]
