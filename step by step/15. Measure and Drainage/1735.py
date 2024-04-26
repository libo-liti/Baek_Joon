def Euclidean(a, b):
    if b == 0:
        return a
    elif b == 1:
        return 1
    return Euclidean(b, a % b)


a, b = map(int, input().split())
c, d = map(int, input().split())
denominator = b * d
numerator = a * d + b * c

LCV = Euclidean(denominator, numerator) if denominator > numerator else Euclidean(
    numerator, denominator)
print(numerator // LCV, denominator // LCV)
