# LCS
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

S1 = input()
S2 = input()
memo = []
for i in range(len(S2)) :
    row = []
    for j in range(len(S1)) :
        if S1[j] == S2[i] :
            if i==0 or j==0 :
                row.append(1)
            else :
                row.append(memo[i-1][j-1]+1)
        else :
            if i==0 or j==0 :
                if i==0 and j==0:
                    row.append(0)
                elif i==0 :
                    row.append(row[j-1])
                else :
                    row.append(memo[i-1][j])
            else :
                row.append(max(row[j-1],memo[i-1][j]))
    memo.append(row)
print(memo[-1][-1])