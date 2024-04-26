def Euclidean(a, b):
    if b == 0:
        return a
    elif b == 1:
        return 1
    return Euclidean(b, a % b)


n = int(input())
for _ in range(n):
    num1, num2 = map(int, input().split())
    lcd = Euclidean(num1, num2) if num1 > num2 else Euclidean(num2, num1)
    result = int(num1 * num2 / lcd)
    print(result)
