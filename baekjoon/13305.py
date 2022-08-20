# 주유소
# 그리디 알고리즘

N = int(input())
road = list(map(int,input().split()))
city = list(map(int,input().split()))
money = 0
i = 0
while i < N :
    if i != N-1 :
        km = road[i]
        for j in range(i+1,N) :
            if city[i] < city[j] and j < N-1 :
                # 이 도시에서 주유하여 가야 할 거리
                km += road[j]
            else :
                money += km * city[i]
                i = j-1
                break
    i += 1
print(money)