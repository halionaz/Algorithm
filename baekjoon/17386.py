# 선분 교차 1
# 기하학 & 선분 교차 판정
# ccw 알고리즘

a=[0,0]
b=[0,0]
c=[0,0]
d=[0,0]
a[0],a[1],b[0],b[1] = map(int,input().split())
c[0],c[1],d[0],d[1] = map(int,input().split())
def ccw(a,b,c) :
    result = (b[0]-a[0])*(c[1]-a[1])-(c[0]-a[0])*(b[1]-a[1])
    if result > 0 :
        return 1
    elif result < 0 :
        return -1
    else :
        return 0
abc = ccw(a,b,c)
abd = ccw(a,b,d)
cda = ccw(c,d,a)
cdb = ccw(c,d,b)
if abc*abd == 0 and cda*cdb == 0 :
    # 두 선분이 한 직선 위에 있을때
    ax,bx,cx,dx = a[0],b[0],c[0],d[0]
    if bx<ax :
        ax,bx = bx,ax
    if dx<cx :
        cx,dx = dx,cx
    if ax<=dx and cx<dx :
        # 두 선분이 겹쳐짐
        print(1)
    else :
        print(0)
elif abc*abd <= 0 and cda*cdb<=0 :
    print(1)
else :
    print(0)