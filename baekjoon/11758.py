# CCW
# 기하학
# ccw 알고리즘

p1 = list(map(int,input().split()))
p2 = list(map(int,input().split()))
p3 = list(map(int,input().split()))
vec1 = [p1[1]-p2[1],p1[0]-p2[0]]
vec2 = [p3[1]-p2[1],p3[0]-p2[0]]
ret = vec1[0]*vec2[1]-vec1[1]*vec2[0]
if ret :
    print(1 if ret>1 else -1)
else :
    print(0)