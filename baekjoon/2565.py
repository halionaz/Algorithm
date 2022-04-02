# 전깃줄
# 다이나믹 프로그래밍

N = int(input())
arr = []
for _ in range(N) :
    arr.append(list(map(int,input().split())))
arr.sort() #A 전봇대 인덱스 순으로 정렬, 만약 B전봇대 위치가 증가하지 않는다면 꼬인것.
memo = [1]*N
ans = 0
#가장 긴 증가하는 수열 구하기
for i in range(N) :
    maximum = 0
    for j in range(i) :
        if arr[j][1] < arr[i][1] and memo[j] > maximum :
            maximum = memo[j]
    memo[i] = maximum + 1
    if memo[i] > ans :
        ans = memo[i]
print(N-ans) #전체 길이 - 가장 긴 수열의 길이 = 없애야할 개수