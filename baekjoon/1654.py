# 랜선 자르기
# 이분 탐색 & 매개 변수 탐색

K,N = map(int,input().split())
arr = [int(input()) for _ in range(K)]

start = 1 # 자를 수 있는 최소 길이
end = max(arr) # 자를 수 있는 최대 길이

ans = 0

while start <= end :
    mid = (start + end)//2
    cnt = 0
    for i in arr :
        # mid 길이로 잘라보자
        cnt += i//mid
    
    if cnt >= N :
        # 이게 되네? 더 늘려보자
        start = mid+1
    else :
        # 이게 안 돼? 더 줄여봐
        end = mid-1
print(end)