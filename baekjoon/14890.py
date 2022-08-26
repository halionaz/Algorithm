# 경사로
# 구현

import sys
input = sys.stdin.readline
N,L = map(int,input().split());
world = []
ans = N+N
# 가로줄 검사
for i in range(N) :
    world.append(list(map(int,input().split())))
    prev = world[i][0]
    lCount = 1
    canPass = True
    haveToGoDown = False
    for j in range(1,N) :
        if haveToGoDown :
            if prev == world[i][j] :
                lCount += 1
                if lCount >= L :
                    haveToGoDown = False
                    lCount = 0
                else :
                    if j == N-1 :
                        canPass = False
                        break
            else :
                canPass = False
                break
        else :
            if prev == world[i][j] :
                lCount+=1
            elif prev+1 == world[i][j] :
                if lCount >= L :
                    lCount=1
                else :
                    canPass = False
                    break
            elif prev-1 == world[i][j] :
                if L == 1 :
                    lCount = 0
                else :
                    haveToGoDown = True
                    if j == N-1 :
                        canPass = False
                        break
                    lCount = 1
            else :
                canPass = False
                break
        prev = world[i][j]
    if not canPass :
        ans -= 1
# 세로줄 검사
for j in range(N) :
    prev = world[0][j]
    lCount = 1
    canPass = True
    haveToGoDown = False
    for i in range(1,N) :
        if haveToGoDown :
            if prev == world[i][j] :
                lCount += 1
                if lCount >= L :
                    haveToGoDown = False
                    lCount = 0
                else :
                    if i == N-1 :
                        canPass = False
                        break
            else :
                canPass = False
                break
        else :
            if prev == world[i][j] :
                lCount+=1
            elif prev+1 == world[i][j] :
                if lCount >= L :
                    lCount=1
                else :
                    canPass = False
                    break
            elif prev-1 == world[i][j] :
                if L == 1 :
                    lCount = 0
                else :
                    haveToGoDown = True
                    if i == N-1 :
                        canPass = False
                        break
                    lCount = 1
            else :
                canPass = False
                break
        prev = world[i][j]
    if not canPass :
        ans -= 1
print(ans)