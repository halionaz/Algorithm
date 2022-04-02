# ACM호텔
# 사칙연산

T = int(input())
inp = []
for i in range(T) :
    inp.append(list(map(int,input().split())))
#0:층수,1:방수,2:몇번째손님
for i in range(T) :
    if inp[i][2]%inp[i][0] == 0 :
        print("{}{:02d}".format(inp[i][0],inp[i][2]//inp[i][0]))
    else :
        print("{}{:02d}".format(inp[i][2]%inp[i][0],inp[i][2]//inp[i][0]+1))
