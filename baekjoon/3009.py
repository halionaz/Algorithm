# 네 번째 점
# 구현 & 기하학

x = []
y = []
for i in range(3): 
    inp = list(map(int,input().split()))
    if inp[0] in x :
        x.remove(inp[0])
    else :
        x.append(inp[0])
    if inp[1] in y :
        y.remove(inp[1])
    else :
        y.append(inp[1])

print(x[0],y[0])