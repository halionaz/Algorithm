# K번째 수 
# 이분 탐색 & 매개 변수 탐색

N = int(input())
k = int(input())

start = 1
end = k
ans = None
while start <= end :
    mid = (start+end)//2
    cnt = 0
    for i in range(1,N+1) :
        cnt += min(mid//i, N) #각 열에서 mid보다 작은 수의 개수
    if cnt < k :
        start = mid + 1
    else :
        ans = mid
        end = mid -1 
        # mid보다 작은 수가 k개 이상인 것을 확인했으나, 
        # 우리는 인덱스를 찾는 것이므로 작은수가 k개 이상인 수 중 최솟값을 탐색해야 한다.
print(ans)