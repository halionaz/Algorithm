# 직각삼각형
# 피타고라스 정리

while True :
    inp = list(map(int,input().split()))
    if inp == [0,0,0] :
        break
    else :
        inp.sort()
        if inp[2]**2 == inp[0]**2+inp[1]**2 :
            print('right')
        else :
            print('wrong')