# 소수의 연속합
# 소수 판정 & 에라토스테네스의 체 & 투 포인터

def prime_list(n):
    numlist = [True]*(n)
    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if numlist[i] == True:    
            for j in range(i+i, n, i): 
                numlist[j] = False
    return [i for i in range(2, n) if numlist[i] == True]
N = int(input())
arr = prime_list(N+1)
leng = len(arr)

if leng == 0 :
    print(0)
elif leng == 1 :
    if arr[0] == N :
        print(1)
    else :
        print(0)
else :
    i,j = 0,1
    tmp = arr[i]+arr[j]
    ans = 0
    while True :
        if tmp == N :
            ans += 1
            if j+1 < leng :
                tmp -= arr[i]
                i += 1
                j += 1
                tmp += arr[j]
            else :
                break
        elif tmp > N :
            if i+1 <= j :
                tmp -= arr[i]
                i += 1
            else :
                if j+1 < leng :
                    j += 1
                    tmp += arr[j]
                else :
                    break
        else :
            if j+1 < leng :
                j += 1
                tmp += arr[j]
            else :
                break
    print(ans)