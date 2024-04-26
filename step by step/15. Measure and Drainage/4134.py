import math


def Prime_Number(n):
    if n == 1 or n == 0:
        return 2
    measure = 2
    limit = math.sqrt(n)
    while limit >= measure:
        if n % measure == 0:
            return 0
        measure += 1
    return n


testCase = int(input())
primeNumber = 0
for _ in range(testCase):
    inputNum = int(input())
    while True:
        primeNumber = Prime_Number(inputNum)
        if primeNumber != 0:
            print(primeNumber)
            break
        inputNum += 1
