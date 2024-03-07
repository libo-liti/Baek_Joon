a, b, c, d, e, f = map(int, input().split())
x = (c - b*a) / a
y = int((a*f-c*d) / (a*e - b*d))
print(a)
print(y)
