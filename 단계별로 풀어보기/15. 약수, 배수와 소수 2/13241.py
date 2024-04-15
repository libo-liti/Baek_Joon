def Euclidean(a, b):
    if b == 0:
        return a
    elif b == 1:
        return 1
    return Euclidean(b, a % b)


num1, num2 = map(int, input().split())
LCV = Euclidean(num1, num2) if num1 > num2 else Euclidean(num2, num1)
result = num1 * num2 // LCV
print(result)
