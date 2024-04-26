num = 1000000
lst = [0, 0] + [1] * (num - 1)
primeLst = []

for i in range(2, num + 1):
    if lst[i] == 1:
        primeLst.append(i)

        for j in range(2 * i, num, i):
            lst[j] = 0

primeSet = set(primeLst)
testCase = int(input())

for _ in range(testCase):
    count = 0
    n = int(input())
    for i in primeLst:
        if i >= n:
            break
        # 앞 뒤 바뀐것도 다 세어주고 마지막에 나누기 2
        if (n - i) in primeSet:
            count += 1
            # 한가지 숫자일 경우 1을 더해줌
            if (n-i) == i:
                count += 1
    print(count // 2)
