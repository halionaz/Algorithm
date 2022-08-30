# N과 M(1)
# 백트래킹

# 이미 있는 기능을 사용해서 구현

# import itertools

# inp = input().split()
# N = int(inp[0])
# M = int(inp[1])
# numList = []
# for i in range(N) :
#     numList.append(i+1)
# newList = list(itertools.permutations(numList,M))

# for i in newList :
#     newStr = ''
#     for j in i :
#         newStr += str(j)+' '
#     print(newStr)

N,M = list(map(int,input().split()))

visit = [None] * N # 중복이 없어야 하므로 들른 수인지 체크용
arr = [None] * M # 정답 기록용

def dfs(N,M,depth) :
    if depth == M : # 만약 깊이가 원하는 만큼 됐으면 출력
        for val in arr :
            print(val,end=' ')
        print('')
        return
    for i in range(N) :
        if not visit[i] :
            visit[i] = True # 들른 수인지 체크
            arr[depth] = i+1 # 정답 기록
            dfs(N,M,depth+1) # 다음 깊이로 고고
            visit[i] = False # 아니었으니까 들른 수 해제
    return

dfs(N,M,0)

