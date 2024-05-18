import sys
input = sys.stdin.readline

num, testCase = map(int, input().rstrip().split())
lst = [0] + list(map(int, input().rstrip().split()))
sumLst = [0] * (num + 1)

for i in range(1, num + 1):
    sumLst[i] = sumLst[i - 1] + lst[i]

for _ in range(testCase):
    a, b = map(int, input().rstrip().split())
    print(sumLst[b] - sumLst[a - 1])
