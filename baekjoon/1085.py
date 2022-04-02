# 직사각형에서 탈출
# 수학

inp = list(map(int,input().split()))
x,y,w,h = inp[0],inp[1],inp[2],inp[3]

ver,hor = 0, 0

if x>w-x :
    ver=w-x
else :
    ver+=x

if y>h-y :
    hor=h-y
else :
    hor=y

if ver>hor :
    print(hor)
else :
    print(ver)