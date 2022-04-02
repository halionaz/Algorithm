# 어린왕자
# 기하학

# 1. 같이 포함되어있는 경우 제외
# 2. 포함 안되어있는 경우 제외
# 3. 출발점을 감싸는 은하수
# 4. 도착점을 감싸는 은하수

T = int(input())
for _ in range(T) :
    start,end = [0,0], [0,0]
    start[0],start[1],end[0],end[1] = map(int,input().split())
    n = int(input())
    arr = []
    ans = 0
    for i in range(n) :
        cx,cy,r = map(int,input().split())
        startDist = (cx-start[0])**2+(cy-start[1])**2
        endDist = (cx-end[0])**2+(cy-end[1])**2
        if (startDist > r**2 and endDist < r**2) or (startDist < r**2 and endDist > r**2) :
            ans += 1
    print(ans)