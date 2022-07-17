# 집으로
# 많은 조건 분기

import math
X,Y,D,T = map(int,input().split())
dist = (X**2+Y**2)**0.5
if D <= T :
    # 점프하는 것 보다 걷는게 빠르다면
    print(dist)
else :
    ans = math.inf
    if dist > D :
        # 점프 할 수 있을 만큼 점프한 이후
        # 이차원이므로 두번 점프해 가는 경우, (2*T)
        # 한번 더 점프해 반대로 걸어가는 경우, (T+(D-(dist%D)))
        # 나머지 거리를 걸어가는 경우 비교 (dist%D)
        ans = (dist//D)*T+min(2*T,T+D-(dist%D),dist%D)

        # 또는 점프를 한번 남겨 둔 후, 거리 조절하여 점프 두번으로 건너가는 경우
        ans = min(ans,(dist//D-1)*T+2*T)
    elif dist == D :
        ans = T
    else :
        # 점프 한번 거리보다 그냥 거리가 짧음
        # 두번 점프하는 것 vs 점프 하고 걸어가는 것 vs 그냥 걸어가는 것
        ans = min(2*T,T+D-dist,dist)
    print(ans)