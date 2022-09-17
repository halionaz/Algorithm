# 암호 만들기
# 브루트포스 알고리즘 & 백트래킹

L,C = map(int,input().split())
strList = list(input().rstrip().split())
strList.sort()
visited = [0]*C

def dfs(depth,n) :
    if depth == L-1 :
        vowel = 0
        conso = 0
        ans = ''
        for i in range(C) :

            if visited[i] :
                ans += strList[i]

                # 자음 & 모음 개수 카운팅을 통한 유효성 판단
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
                # 솔직히 어차피 정렬된 상태에서 선형적으로 탐색중이기에
                # 당연히 i는 방문하지 않았을 것임. 따라서 별로 의미있는 조건문은 아님
                visited[i] = 1
                dfs(depth+1,i)
                visited[i] = 0

for i in range(C-L+1) :
    visited[i] = 1
    dfs(0,i)
    visited[i] = 0