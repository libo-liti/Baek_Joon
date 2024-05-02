import sys
input = sys.stdin.readline

s = set()
testCase = int(input().strip())

for _ in range(testCase):
    data = input().rstrip()
    try:
        operator, x = data.split()
        x = int(x)
    except:
        operator = data
    if operator == "add":
        s.add(x)
    elif operator == "remove":
        s.discard(x)
    elif operator == "check":
        print(1) if x in s else print(0)
    elif operator == "toggle":
        s.remove(x) if x in s else s.add(x)
    elif operator == "all":
        s = set(range(1, 21))
    elif operator == "empty":
        s.clear()
