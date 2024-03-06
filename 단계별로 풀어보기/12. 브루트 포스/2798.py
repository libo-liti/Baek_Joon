n, goal = map(int, input().split())
lst = list(map(int, input().split()))
lst.sort()
max = 0

c1, c2, c3 = 0, 1, 2
while True:
    if max < lst[c1] + lst[c2] + lst[c3] <= goal:
        max = lst[c1] + lst[c2] + lst[c3]

    if max == goal:
        break
    elif c1 == len(lst) - 3:
        break
    else:
        c3 += 1
        if c3 == len(lst) - 1:
            c2 += 1
            c3 = c2 + 1
        elif c2 == len(lst) - 2:
            c1 += 1
            c2 = c1 + 1
            c3 = c2 + 1
print(max)
