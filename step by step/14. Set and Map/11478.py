str = input()
set1 = set()
for i in range(len(str)):
    for j in range(len(str) - i):
        set1.add(str[j: j + i + 1])
print(len(set1))
