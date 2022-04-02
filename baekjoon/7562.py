# 나이트의 이동
# 너비 우선 탐색

import sys
from collections import deque
input = sys.stdin.readline
vi = (1,2,2,1,-1,-2,-2,-1)
vj = (2,1,-1,-2,-2,-1,1,2)

def main() :
    T = int(input())
    for _ in range(T) :
        I = int(input())
        x,y = map(int,input().split())
        z,h = map(int,input().split())
        board = [[-1]*I for _ in range(I)]
        board[x][y] = 0
        queue = deque([(x,y)])
        while len(queue) :
            i,j = queue.popleft()
            if i == z and j == h :
                break
            for l in range(8) :
                newi = i + vi[l]
                newj = j + vj[l]
                if 0<=newi<I and 0<=newj<I and board[newi][newj] == -1:
                    queue.append((newi,newj))
                    board[newi][newj] = board[i][j]+1
        print(board[z][h])

main()