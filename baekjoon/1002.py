# 터렛
# 기하학

# 두 원이 겹치는 경우와 내외에 존재하는 경우를 계산해야 하는 기하 문제

T= int(input())
for i in range(T) :
    inp=list(map(int,input().split()))
    cho = [inp[0],inp[1]]
    baek = [inp[3],inp[4]]
    r1,r2 = inp[2],inp[5]
    dist = ((cho[0]-baek[0])**2+(cho[1]-baek[1])**2)**0.5
    if dist == 0 and r1 == r2 :
        print(-1)
    elif dist == r1+r2 or (dist != 0 and dist == abs(r2-r1)) :
        print(1)
    elif abs(r2-r1)<dist<r1+r2 :
        print(2)
    else :
        print(0)