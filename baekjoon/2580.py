# 스도쿠
# 백트래킹
# py_output_at_once

import sys
sudoku = [list(map(int,input().split())) for _ in range(9)]
zero = [[i,j] for i in range(9) for j in range(9) if sudoku[i][j] == 0]
def sdoku(index) :
    if index == len(zero) :
        for i in sudoku :
            print(*i)
        sys.exit(0)
    else :
        x = zero[index][0]
        y = zero[index][1]
        dx = (x//3)*3
        dy = (y//3)*3
        numList = [True] * 9
        # 가로 세로 체크
        for i in range(9) :
            if sudoku[i][y] != 0 :
                numList[sudoku[i][y]-1] = False
            if sudoku[x][i] != 0 :
                numList[sudoku[x][i]-1] = False
        # 3*3 정사각형 체크
        for i in range(dx,dx+3) :
            for j in range(dy,dy+3) :
                if sudoku[i][j] != 0 :
                    numList[sudoku[i][j]-1] = False
        for i in range(9) :
            if numList[i] :
                sudoku[x][y] = i+1
                sdoku(index+1)
                sudoku[x][y] = 0
sdoku(0)