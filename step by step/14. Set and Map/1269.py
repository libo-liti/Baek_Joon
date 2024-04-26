n, m = map(int, input().split())
lst1 = list(map(int, input().split()))
lst2 = list(map(int, input().split()))
print(len(set(lst1) - set(lst2)) + len(set(lst2) - set(lst1)))
