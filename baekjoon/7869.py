# 두 원 
# 기하학 & 많은 조건 분기

import math
x1,y1,r1,x2,y2,r2 = map(float,input().split())
dist = ((x1-x2)**2+(y1-y2)**2)**0.5
rr1 = r1**2
rr2 = r2**2
ans = 0
if(dist>r1+r2) :
    ans = 0
elif dist <= r1-r2 :
    ans = math.pi * rr2
elif dist <= r2-r1 :
    ans = math.pi * rr1
else :
    t = 2*(math.acos((rr2+dist**2-rr1)/(2*r2*dist)))
    p = 2*(math.acos((rr1+dist**2-rr2)/(2*r1*dist)))
    a1 = 0.5*t*rr2 - 0.5*rr2*math.sin(t)
    a2 = 0.5*p*rr1 - 0.5*rr1*math.sin(p)
    ans = a1 + a2
print('%.3f'%ans)