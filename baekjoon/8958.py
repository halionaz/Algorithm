# OX퀴즈
# 문자열

N = int(input())
points = []

for i in range(N) :
    case = input()
    point = 0
    combo = 1
    for j in range(len(case)) :
        if case[j] == 'O' :
            point += combo
            combo += 1
        else :
            combo = 1
    points.append(point)

for i in points :
    print(i)