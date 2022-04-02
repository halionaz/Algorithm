# 빙고
# 구현

bingo = []
사회자 = []
for _ in range(5) :
    bingo.append(list(map(int,input().split())))
for _ in range(5) :
    for i in list(map(int,input().split())) :
        사회자.append(i)
for i in range(25) :
    score = 0
    for j in range(5) : #빙고 지우기 수행
        if 사회자[i] in bingo[j] :
            bingo[j][bingo[j].index(사회자[i])] = 0
    if i > 9 :
        isCross1True = isCross2True = 1
        for j in range(5) :
            isVerticalTrue = 1
            if bingo[j] == [0,0,0,0,0] : #가로줄 검사
                score += 1
            for l in range(5) : #세로줄 검사
                if bingo[l][j] != 0 :
                    isVerticalTrue = 0
                    break
            if isVerticalTrue :
                score += 1
            if bingo[j][j] != 0 : #대각선 (좌측상단->우측하단) 검사
                isCross1True = 0
            if bingo[j][4-j] != 0 : #대각선 (우측상단->좌측하단) 검사 
                isCross2True = 0
        if isCross1True :
            score += 1
        if isCross2True :
            score += 1
        if score >= 3 :
            print(i+1)
            break
