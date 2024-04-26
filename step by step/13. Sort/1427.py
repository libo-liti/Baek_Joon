n = int(input())
lst = list(map(int, str(n)))
lst.sort(reverse=True)
print(''.join(map(str, lst)))
