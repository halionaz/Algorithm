# 아이돌
# 2-sat & 강한 연결 요소

# C++로 구현했을 때 계속 Out of Bound 런타임 에러가 뜸
# 도저히 무엇이 문제인지 모르겠어서 Python으로 전환

import sys
input = sys.stdin.readline

def DFS(cur) :
    visited[cur] = True
    for i in line[cur] :
        if not visited[i] :
            DFS(i)
    stck.append(cur)

def reverseDFS(cur) :
    visited[cur] = True
    scc[cur] = ind
    for i in reverseLine[cur] :
        if not visited[i] :
            reverseDFS(i)


while True :
    try :
        N,M = map(int, input().split());
        line = [[] for _ in range(N*2+2)]
        reverseLine = [[] for _ in range(N*2+2)]
        visited = [False]*(N*2+2)
        scc = [-1]*(N*2+2)
        stck = []
        ind = -1
        for _ in range(M) :
            a,b = map(int, input().split())
            if a < 0 :
                a = (-a)*2
            else :
                a = a*2-1
            if b < 0 :
                b = (-b)*2
            else :
                b = b*2-1
            if a%2 :
                notA = a+1
            else :
                notA = a-1
            if b%2 :
                notB = b+1
            else :
                notB = b-1
            line[notA].append(b)
            reverseLine[b].append(notA)
            line[notB].append(a)
            reverseLine[a].append(notB)
        for i in range(1,2*N+1) :
            if not visited[i] :
                DFS(i)
        for i in range(0, len(visited)) :
            visited[i] = False
        
        while len(stck) :
            top = stck[-1]
            if not visited[top] :
                ind += 1
                reverseDFS(top)
            stck.pop()
        
        ans = True

        if scc[1] <= scc[2] :
            ans = False
        
        if ans :
            for i in range(1,N+1) :
                if scc[i*2-1] == scc[i*2] :
                    ans = False
                    break
        
        print('yes' if ans else 'no')

    except :
        break