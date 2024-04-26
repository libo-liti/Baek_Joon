n = int(input())
lst = list(map(int, input().split()))
lst_temp = list(set(lst))
lst_temp.sort()
dictionary = {value: i for i, value in enumerate(lst_temp)}
for i in range(n):
    lst[i] = dictionary.get(lst[i])
print(*lst)
