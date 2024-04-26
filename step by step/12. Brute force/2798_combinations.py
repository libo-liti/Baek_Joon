from itertools import combinations

n, goal = list(map(int, input().split()))
lst = list(map(int, input().split()))
max = 0

for i in combinations(lst, 3):
    if max < sum(i) <= goal:
        max = sum(i)
print(max)
