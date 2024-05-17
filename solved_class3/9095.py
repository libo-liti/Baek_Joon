lst = [0, 1, 2, 4] + [0] * 7
for i in range(4, 11):
    lst[i] = lst[i - 1] + lst[i - 2] + lst[i - 3]


testCase = int(input())
for _ in range(testCase):
    n = int(input())
    print(lst[n])
