# 랜선 자르기
# 이분 탐색 & 매개 변수 탐색

K,N = map(int,input().split())
arr = [int(input()) for _ in range(K)]
start = 1
end = max(arr)
ans = 0
while start <= end :
    mid = (start + end)//2
    cnt = 0
    for i in arr :
        cnt += i//mid
    if cnt >= N :
        start = mid+1
    else :
        end = mid-1
print(end)