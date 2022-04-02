# 두 수의 합
# 두 포인터

# 두 값의 합이 x와 같은 경우 i를 올리거나 j를 내리기만 해서는 절대 x와 같아질 수 없음
# 따라서 같은 경우엔 둘다 조정

# x보다 값이 크면 j를 내림
# x보다 값이 작으면 i를 올림

n = int(input())
arr = sorted(list(map(int,input().split())))
x = int(input())
ans = 0
if n == 1 :
    if arr[0] == x :
        ans = 1
else :
    i,j = 0, n-1
    while i < j :
        if arr[i] + arr[j] == x :
            ans+=1
            i += 1
            j -= 1
        elif arr[i]+arr[j] > x :
            j -= 1
        else :
            i += 1
print(ans)