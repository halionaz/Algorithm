# 별 찍기 - 10
# 재귀 & 분할 정복

# 죤내 어렵습니다
# 첫 재귀 문제여서 이해하기 너무 힘들었던 문제

N = int(input())

def star(i,j,n) :
    if (i//n)%3==1 and (j//n)%3==1 :
        print(' ',end='')
    else :
        if n//3 == 0 :
            print('*',end='')
        else :
            star(i,j,n//3)

for i in range(N) :
    for j in range(N) :
        star(i,j,N)
    print()
