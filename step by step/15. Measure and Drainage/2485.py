import sys
input = sys.stdin.readline


def Euclidean(a, b):
    if b == 0:
        return a
    elif b == 1:
        return 1
    return Euclidean(b, a % b)


n = int(input().rstrip())
lst = []
intervalLst = []
LCD = 0
count = 0

for i in range(n):
    temp = int(input().rstrip())
    lst.append(temp)
    if i == 0:
        continue

    interval = lst[i] - lst[i - 1]
    if len(intervalLst) == 1:
        LCD = Euclidean(
            interval, intervalLst[-1]) if interval > intervalLst[-1] else Euclidean(intervalLst[-1], interval)
    else:
        LCD = Euclidean(interval, LCD) if interval > LCD else Euclidean(
            LCD, interval)
    intervalLst.append(interval)
for i in intervalLst:
    count += i // LCD - 1
print(count)
