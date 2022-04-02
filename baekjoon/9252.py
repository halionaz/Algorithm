# LCS 2
# 다이나믹 프로그래밍

# 격자무늬 채우기를 통해 푸는 방법
# 직관적으로 이해하기 힘듦! 복습 철저히!
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