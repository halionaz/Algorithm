# 체스판 다시 칠하기
# 브루트포스 알고리즘

inp = list(map(int,input().split()))

board = []
for i in range(inp[0]) :
    board.append(input())

ans = 64
for i in range(inp[0]-7) :
    for j in range(inp[1]-7) :
        case1 = 0 # 가장 왼쪽 위가 B인 case
        case2 = 0 # 가장 왼쪽 위가 W인 case
        for l in range(8) :
            for m in range(8) :
                if (l+m)%2 == 0 :
                    if board[l+i][m+j] == 'W' :
                        case1 += 1
                    else :
                        case2 += 1
                else :
                    if board[l+i][m+j] == 'W' :
                        case2 += 1
                    else :
                        case1 += 1
        ans = min(ans, case1, case2)
print(ans)