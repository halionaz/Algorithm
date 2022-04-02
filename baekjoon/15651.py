# N과 M (3)
# 백트래킹

N, M = map(int,input().split())
arr = [None]*M

def card(depth) :
    if depth == M :
        print(' '.join([str(i) for i in arr]))
        return
    for i in range(N) :
        if depth == 0 or i >= arr[depth-1]-1 :
            arr[depth] = i+1
            card(depth+1)

card(0)