# LCS 2
# 다이나믹 프로그래밍

# 격자무늬 채우기를 통해 푸는 방법

# 두 문자열을 하나는 가로축, 하나는 세로축으로 두고
# 격자를 하나씩 채워 나감
# 두 문자가 같다면 왼쪽 대각선 값 + 1을 채우고
# 두 문자가 다르다면 왼쪽 값이나 위 값 중 큰 값을 채움

# 다이나믹 프로그래밍으로 해석하자면 
# memo[i][j] :: 1번 문자열의 i번까지 확인하고, 2번 문자열의 j번까지 확인했을 때
# 최장 문자열의 길이로, 
# 만약 i번과 j번이 같지 않다면 memo[i][j] = max(memo[i-1][j], memo[i][j-1])
# 만약 i번과 j번이 같다면 memo[i][j] = memo[i-1][j-1] + 1

# 다만 이 문제는 9251번과 달리 최장 공통 부분 수열을 출력도 해야 하므로
# 메모이제이션 할 때 백트래킹이 가능하도록 주소도 남겨둠

S1 = input()
S2 = input()
memo = []
for i in range(len(S2)) :
    row = []
    for j in range(len(S1)) :
        if S1[j] == S2[i] :
            if i==0 or j==0 :
                row.append([1,-1,-1,1])
            else :
                row.append([memo[i-1][j-1][0]+1,i-1,j-1,1])
        else :
            if i==0 or j==0 :
                if i==0 and j==0:
                    row.append([0,-1,-1,0])
                elif i==0 :
                    row.append([row[j-1][0],i,j-1,0])
                else :
                    row.append([memo[i-1][j][0],i-1,j,0])
            else :
                if row[j-1][0] > memo[i-1][j][0] :
                    row.append([row[j-1][0],i,j-1,0])
                else :
                    row.append([memo[i-1][j][0],i-1,j,0])
    memo.append(row)
i = len(S2)-1
j = len(S1)-1
print(memo[i][j][0])
ans = []
while True :
    
    if memo[i][j][3] :
        ans.append(str(S1[j]))

    if memo[i][j][1] == -1 :
        break
    else :
        i,j = memo[i][j][1],memo[i][j][2]
ans.reverse()
print(''.join(ans))