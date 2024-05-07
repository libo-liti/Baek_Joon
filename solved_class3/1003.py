def fibo(n):
    lst = [0] * (n + 1)
    lst[0] = 1
    if n != 0:
        lst[1] = 0

    # 0 호출 개수
    for i in range(2, n + 1):
        lst[i] = lst[i - 1] + lst[i - 2]
    zeroCnt = lst[n]

    # 1 호출 개수
    lst = [0] * (n + 1)
    if n != 0:
        lst[1] = 1

    for i in range(2, n + 1):
        lst[i] = lst[i - 1] + lst[i - 2]
    oneCnt = lst[n]

    print(zeroCnt, oneCnt)
    return


testCase = int(input())
for _ in range(testCase):
    n = int(input())
    fibo(n)
