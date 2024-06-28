def dfs(a, b, n):
    global white, blue
    zero = 0
    for i in range(a, a + n):
        for j in range(b, b + n):
            if lst[i][j] == 0:
                zero += 1
    if zero == n ** 2:
        white += 1
    elif zero == 0:
        blue += 1
    else:
        # 좌상
        dfs(a, b, n // 2)
        # 우상
        dfs(a + n // 2, b, n // 2)
        # 좌하
        dfs(a, b + n // 2, n // 2)
        # 우하
        dfs(a + n // 2, b + n // 2, n // 2)


num = int(input())
lst = [list(map(int, input().split()))for _ in range(num)]
white = 0
blue = 0
dfs(0, 0, num)
print(white, blue)
