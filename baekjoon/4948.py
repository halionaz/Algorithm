# 베르트랑 공준
# 소수 판정 & 에라토스테네스의 체

while True :
    n = int(input())
    if n == 0 :
        break
    else :
        arr = [True]*(2*n+1)
        arr[0],arr[1] = False,False
        for i in range(int((2*n+1)**0.5)+1) :
            if arr[i] :
                for j in range(i+i,len(arr),i) :
                    arr[j] = False
        count = 0
        for i in range(n+1,2*n+1) :
            if arr[i] :
                count+=1
        print(count)