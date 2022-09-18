# 종이의 개수
# 분할 정복 & 재귀

import sys
input = sys.stdin.readline

N = int(input())
arr = []

for _ in range(N) :
    arr.append(list(map(int,input().split())))

cnt_m1 = cnt_0 = cnt_1 = 0

# x, y는 사각형의 시작점, n은 사각형 한 변 길이
def cut(x,y,n) :
    global cnt_m1,cnt_0,cnt_1
    kind = arr[y][x]
    isDone = True
    for i in range(y,y+n) :
        for j in range(x, x+n) :
            if arr[i][j] != kind :
                isDone = False
                break
        if not isDone :
            break
    if isDone :
        if kind == -1 :
            cnt_m1 += 1
        elif kind == 0 :
            cnt_0 += 1
        else :
            cnt_1 += 1
    else :
        length = n//3
        for i in range(3) :
            for j in range(3) :
                cut(x + i*length, y + j*length, length)

cut(0,0,N)

print(cnt_m1)
print(cnt_0)
print(cnt_1)