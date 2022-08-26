# 스타트와 링크
# 백트래킹 & 브루트포스 알고리즘

import sys
N = int(sys.stdin.readline())
tab = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
member = [False]*N
ans = 100000
def dfs(last,depth) :
    global ans
    if depth == N/2 :
        # 팀이 모두 확정나면
        synergy1,synergy2 = 0,0
        for i in range(N) :
            for j in range(N) :
                if member[i] and member[j] :
                    synergy1 += tab[i][j]
                elif not member[i] and not member[j] :
                    synergy2 += tab[i][j]
        gap = abs(synergy1-synergy2)
        if gap < ans :
            ans = gap
            # 만약 ans보다 작다면 답 갱신
        return
    for i in range(last,N) :
        if not member[i] :
            member[i] = True
            dfs(i,depth+1)
            member[i] = False
dfs(0,0)
print(ans)