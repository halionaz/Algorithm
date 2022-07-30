# RGB거리
# 다이나믹 프로그래밍

N = int(input())
cost = [] 
for _ in range(N) :
    cost.append(list(map(int,input().split())))
arr = [cost[0]] # arr[i][j] :: i번째 집을 j로 칠하려 할 때 드는 최소 비용
for i in range(1,N) :
    arr.append([min(arr[i-1][1]+cost[i][0],arr[i-1][2]+cost[i][0]),min(arr[i-1][0]+cost[i][1],arr[i-1][2]+cost[i][1]),min(arr[i-1][0]+cost[i][2],arr[i-1][1]+cost[i][2])])
print(min(arr[N-1]))