import sys
from collections import deque
input = sys.stdin.readline


def bfs(hh, ww):
    global lst
    deq = deque()
    deq.append([hh, ww])
    while deq:
        h, w = deq.popleft()
        if w - 1 >= 0 and lst[h][w - 1] == 1:
            lst[h][w - 1] = 0
            deq.append([h, w - 1])
        if w + 1 < len(lst[0]) and lst[h][w + 1] == 1:
            lst[h][w + 1] = 0
            deq.append([h, w + 1])
        if h + 1 < len(lst) and lst[h + 1][w] == 1:
            lst[h + 1][w] = 0
            deq.append([h + 1, w])
        if h - 1 >= 0 and lst[h - 1][w] == 1:
            lst[h - 1][w] = 0
            deq.append([h - 1, w])
    return


testCase = int(input().rstrip())
for _ in range(testCase):
    cnt = 0
    width, height, n = map(int, input().split())
    lst = [[0 for _ in range(width)] for _ in range(height)]

    for _ in range(n):
        j, i = map(int, input().split())
        lst[i][j] = 1

    for i in range(height):
        for j in range(width):
            if lst[i][j] == 1:
                lst[i][j] = 0
                bfs(i, j)
                cnt += 1
    print(cnt)
