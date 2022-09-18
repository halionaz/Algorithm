# 부분합
# 두 포인터 & 누적 합

N,S = map(int,input().split())
arr = list(map(int,input().split()))
i,j = 0,0
ans = N+1
tmp = arr[0]
while True :
    if tmp < S :
        # 목표값보다 작으면 범위를 늘려줌
        if j+1 < N :
            j += 1
            tmp += arr[j]
        else :
            # 더 늘릴 수가 없음
            break
    else :
        # 최소 길이 갱신
        ans = min(ans,j-i+1)
        if i+1 <= j :
            # 범위 줄여줌
            tmp -= arr[i]
            i += 1
        else :
            if j+1<N :
                j += 1
                tmp += arr[j]
            else :
                break
print(0 if ans == N+1 else ans)
