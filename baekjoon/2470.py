# 두 용액
# 두 포인터 & 이분 탐색

# 전형적인 투 포인터 알고리즘
# 두 개를 더한 값이 그 전 값보다 0에 근접하면 갱신
# 더한 값이 0보다 크다면 더 작아지는 것이 유리하므로 더 큰 값을 내림
# 더한 값이 0보다 작으면 더 커지는 것이 유리하므로 더 작은 값을 올림

N = int(input())
arr = sorted(list(map(int,input().split())))
i,j = 0, N-1
tmp = 999999999999999999999
ans = []
while i < j :
    val = arr[i]+arr[j] 
    absVal = abs(val)
    
    if absVal < tmp :
        tmp = absVal
        ans = [i,j]

    if val == 0 :
        break
    elif val > 0 :
        j -= 1
    else :
        i += 1
print(arr[ans[0]],arr[ans[1]])