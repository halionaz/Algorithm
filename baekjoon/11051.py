# 이항 계수 2
# 조합론 & 다이나믹 프로그래밍
# bottom-up

N,K = map(int,input().split())
pt = []
pt.append([1])
pt.append([1,1])
for i in range(2,N+1) :
    arr = [1]
    for j in range(i-1) :
        arr.append(pt[i-1][j]+pt[i-1][j+1])
    arr.append(1)
    pt.append(arr)
print(pt[N][K]%10007)