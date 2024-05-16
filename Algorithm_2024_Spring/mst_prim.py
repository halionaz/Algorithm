inf = 987654321

n = int(raw_input())
m = int(raw_input())

q = [[]]


def min_heapify(i):
    l = i * 2
    r = i * 2 + 1
    min = i
    if l < len(q) and q[l][0] < q[i][0]:
        min = l
    if r < len(q) and q[r][0] < q[min][0]:
        min = r
    if min != i:
        q[i], q[min] = q[min], q[i]
        min_heapify(min)


def build_min_heap():
    for i in range(n):
        if i == 0:
            q.append([0, 0])
        else:
            q.append([inf, i])


def extract_min():
    ret = q[1]
    if len(q) == 2:
        q.pop()
    else:
        q[1] = q.pop()
        min_heapify(1)
    return ret


def decrease_key(i, val):
    if val > q[i][0]:
        return
    q[i][0] = val
    while i > 1 and q[i // 2][0] > q[i][0]:
        q[i], q[i // 2] = q[i // 2], q[i]
        i //= 2


line = []
parents = []

for i in range(n):
    line.append([])
    parents.append(-1)

for i in range(m):
    a, b, w = map(int, raw_input().split(","))
    line[a].append((b, w))
    line[b].append((a, w))


def mst_prim():
    build_min_heap()
    while len(q) > 1:
        _, cur = extract_min()
        for next, cost in line[cur]:
            for i in range(1, len(q)):
                if q[i][1] == next:
                    if cost < q[i][0]:
                        parents[next] = cur
                        decrease_key(i, cost)
                    break


mst_prim()

for i in range(1, n):
    print(parents[i])
