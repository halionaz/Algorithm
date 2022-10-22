# 배스킨라빈스~N~귀엽고~깜찍하게~
# 수학 & 게임 이론 

N, M = map(int, input().split())

if(0 < (N-1)%(M+1) <= M) :
    print("Can win")
else :
    print("Can't win")