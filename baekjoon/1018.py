# 체스판 다시 칠하기
# 브루트포스 알고리즘

inp = list(map(int,input().split()))

board = []
for i in range(inp[0]) :
    board.append(input())

min = 64
for i in range(inp[0]-7) :
    for j in range(inp[1]-7) :
        case = 0
        case1 = 0
        case2 = 0
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
        if case1 > case2 :
            case = case2
        else : 
            case = case1
        if case < min :
            min = case
print(min)

        