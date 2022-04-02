# LCS
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