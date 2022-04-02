# 평균은 넘겠지
# 사칙연산

C = int(input())

for i in range(C) :
    inp = list(map(int,input().split()))
    inp.pop(0)
    aver = sum(inp)/len(inp)
    num = 0
    for j in inp :
        if j > aver :
            num += 1
    print(format(100*num/len(inp),'.3f')+'%')