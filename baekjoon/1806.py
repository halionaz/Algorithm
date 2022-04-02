# 부분합
# 두 포인터

N,S = map(int,input().split())
arr = list(map(int,input().split()))
i,j = 0,0
ans = N+1
tmp = arr[0]
while True :
    if tmp < S :
        if j+1 < N :
            j += 1
            tmp += arr[j]
        else :
            break
    else :
        ans = min(ans,j-i+1)
        if i+1 <= j :
            tmp -= arr[i]
            i += 1
        else :
            if j+1<N :
                j += 1
                tmp += arr[j]
            else :
                break
print(0 if ans == N+1 else ans)
