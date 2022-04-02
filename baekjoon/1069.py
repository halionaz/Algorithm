# 집으로
# 많은 조건 분기

import math
X,Y,D,T = map(int,input().split())
dist = (X**2+Y**2)**0.5
if D <= T :
    # 뛰는 것 보다 걷는게 빠르다면
    print(dist)
else :
    ans = math.inf
    if dist > D :
        # 점프 할 수 있을 만큼 점프한 이후
        # 이차원이므로 두번 점프해 가는 경우, 
        # 한번 더 점프해 반대로 걸어가는 경우, 
        # 나머지 거리를 걸어가는 경우
        # 비교
        ans = (dist//D)*T+min(2*T,T+D-(dist%D),dist%D)
        ans = min(ans,(dist//D-1)*T+2*T)
    elif dist == D :
        ans = T
    else :
        ans = min(2*T,T+D-dist,dist)
    print(ans)