# 선분 교차 3
# 기하학 & 선분 교차 판정

# 쥰내 어렵고 내가 직접 푼거라고 하기 애매하다
# 무조건 나중에 복습 해야됨..

def findFunc(x1,y1,x2,y2):
    a=findA(x1,y1,x2,y2)
    if a==float('inf'):
        if y1==y2:
            return x1,y1,True
        return x1,float('inf'), True
    b= findB(x1,y1,a)
    return a,b,False

def findA(x1,y1,x2,y2):
    if x1==x2:
        return float('inf')
    else:
        return (y2-y1)/(x2-x1)
def findB(x1,y1,a):
    return y1-a*x1
def findCrossPoint(x1,y1,x2,y2,x3,y3,x4,y4):
    a1,b1,flag1= findFunc(x1,y1,x2,y2)
    a2,b2,flag2= findFunc(x3,y3,x4,y4)
    if flag1 and b1==float('inf'):
        return a1,a2*a1+b2
    elif flag1:
        return x1,x2
    if flag2 and b2==float('inf'):
        return a2,a1*a2+b1
    elif flag2:
        return x3,x4
    else:
        if a2!=a1:
            return  (b1-b2)/(a2-a1), (b1*a2-b2*a1)/(a2-a1)
        else: 
            if min(x1,x2)<=max(x3,x4) and min(x3,x4)<=max(x1,x2) and min(y1,y2)<=max(y3,y4) and min(y3,y4)<=max(y1,y2):
                if min(x1,x2)==max(x3,x4):
                        return min(x1,x2),min(x1,x2)*a1+b1
                if max(x1,x2)==min(x3,x4):
                        return max(x1,x2),max(x1,x2)*a1+b1
                else:
                    return float('inf'),float('inf')
x1, y1, x2, y2=map(int, input().split())
x3, y3, x4, y4=map(int, input().split())
xans=float('inf')
yans=float('inf')
answer=0
didanswer=False
def ccw(x1,y1,x2,y2,x3,y3):
    tmp= (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)
    if tmp > 0:
        return 1
    elif tmp < 0:
        return -1
    else:
        return 0
if ccw(x1,y1,x2,y2,x3,y3) * ccw(x1,y1,x2,y2,x4,y4)==0 and ccw(x3,y3,x4,y4,x1,y1) * ccw(x3,y3,x4,y4,x2,y2)==0:
    didanswer=True
    if min(x1,x2)<=max(x3,x4) and min(x3,x4)<=max(x1,x2) and min(y1,y2)<=max(y3,y4) and min(y3,y4)<=max(y1,y2):
        answer=1
        xans, yans=findCrossPoint(x1,y1,x2,y2,x3,y3,x4,y4)
if ccw(x1,y1,x2,y2,x3,y3) * ccw(x1,y1,x2,y2,x4,y4)<=0 and ccw(x3,y3,x4,y4,x1,y1) * ccw(x3,y3,x4,y4,x2,y2)<=0:
    if not didanswer:
        xans, yans=findCrossPoint(x1,y1,x2,y2,x3,y3,x4,y4)
        answer=1
print(answer)
if (xans!=float('inf') and yans!=float('inf')):
    if xans%1==0:
        xans=round(xans)
    if yans%1==0:
        yans=round(yans)
    print(xans,yans)
elif not (xans == float('inf') and yans == float('inf')) : #이게 맞나? 
    print(0,0);
