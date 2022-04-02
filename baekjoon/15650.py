# N과 M (2)
# 백트래킹

N, M = map(int,input().split())
arr = [None]*M
def comb(N,M,depth) :
    if depth == M :
        print(' '.join([str(i+1) for i in arr]))
        return
    for i in range(N) :
        if depth == 0 or i > arr[depth-1] :
            arr[depth] = i
            comb(N,M,depth+1)
comb(N,M,0)