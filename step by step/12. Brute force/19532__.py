a, b, c, d, e, f = map(int, input().split())
x = ((e*c)-(b*f)) / ((a*e)-(d*b))
y = ((a*f)-(d*c)) / ((a*e)-(d*b))
print(int(x), int(y))
