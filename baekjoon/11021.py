# A+B - 7
# 사칙연산

T = int(input())

case = []
for i in range(T) :
    case.append(input().split())

for i in range(len(case)) :
    print("Case #{}: {}".format(i+1,int(case[i][0])+int(case[i][1])))