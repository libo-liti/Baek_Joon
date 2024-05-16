def virus(index):
    global visit
    for i in v[index]:
        if i not in visit:
            visit.add(i)
            virus(i)
    return


nodeNum = int(input())
edgeNum = int(input())
visit = set()
v = [[] for _ in range(nodeNum + 1)]

for _ in range(edgeNum):
    edge1, edge2 = map(int, input().split())
    v[edge1].append(edge2)
    v[edge2].append(edge1)

virus(1)
if nodeNum == 1:
    print(0)
else:
    print(len(visit) - 1)
