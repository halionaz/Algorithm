# 다각형의 면적
# 다각형의 넓이

# 벡터 외적을 통해 넓이를 구할 수 있음

import sys
input = sys.stdin.readline
N = int(input())
pos = []
for _ in range(N) :
    x,y = map(int,input().split())
    pos.append([x,y])
def ccw(a,b,c) :
    vec1 = [pos[b][1]-pos[a][1],pos[b][0]-pos[a][0]]
    vec2 = [pos[c][1]-pos[a][1],pos[c][0]-pos[a][0]]
    return (vec1[0]*vec2[1]-vec1[1]*vec2[0])/2;
ans = 0
for i in range(1,N-1) :
    ans += ccw(0,i,i+1)
print(abs(ans))