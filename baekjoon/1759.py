# 암호 만들기
# 브루트포스 알고리즘 & 백트래킹

L,C = map(int,input().split())
strList = list(input().rstrip().split())
strList.sort()
visited = [0]*C
vowel = []
def dfs(depth,n) :
    if depth == L-1 :
        vowel = 0
        conso = 0
        ans = ''
        for i in range(C) :
            if visited[i] :
                ans += strList[i]
                if strList[i] == 'a' or strList[i] == 'e' or strList[i] == 'i' or strList[i] == 'o' or strList[i] == 'u' :
                    vowel += 1
                else :
                    conso += 1
        if vowel >= 1 and conso >= 2 :
            print(ans)
        return
    else :
        for i in range(n+1,C) :
            if not visited[i] :
                visited[i] = 1
                dfs(depth+1,i)
                visited[i] = 0
for i in range(C-L+1) :
    visited[i] = 1
    dfs(0,i)
    visited[i] = 0