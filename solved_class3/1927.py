import heapq
import sys
input = sys.stdin.readline

heap = []
n = int(input())

for _ in range(n):
    op = int(input())

    if op == 0:
        if heap != []:
            print(heapq.heappop(heap))
        else:
            print(0)
    else:
        heapq.heappush(heap, op)
