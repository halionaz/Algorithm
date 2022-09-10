# N과 M (4)
# 백트래킹
# py_output_at_once

N, M = map(int,input().split())
arr = [None]*M

def card(depth) :
    if depth == M :
        print(*arr)
        return
    for i in range(N) :
        if depth == 0 or i >= arr[depth-1]-1 :
            arr[depth] = i+1
            card(depth+1)

card(0)