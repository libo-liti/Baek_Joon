n = int(input())
five = n // 5
three = (n - five * 5) // 3
while True:
    if five * 5 + three * 3 == n:
        print(five + three)
        break

    if five - 1 >= 0:
        five -= 1
        three = (n - five * 5) // 3
    else:
        print(-1)
        break
