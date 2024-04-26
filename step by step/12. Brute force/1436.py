n = int(input())
num = 0
i = 666
while True:
    tem = str(i)
    length = len(tem) - 1
    for j in range(length - 1):
        if tem[length - j] == tem[length - j - 1] == tem[length - j - 2] == '6':
            num += 1
            break
    if num == n:
        print(i)
        break
    i += 1
