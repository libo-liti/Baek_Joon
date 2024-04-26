n = int(input())
i = n - 54
if n < 55:
    i = 0
while True:
    if n == i:
        print(0)
        break
    else:
        j = i
        sum = j
        while j // 10:
            sum += j % 10
            j //= 10
        sum += j % 10

        if n == sum:
            print(i)
            break
        i += 1
