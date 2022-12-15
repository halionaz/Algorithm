# 골드바흐의 추측
# 소수 판정 & 에라토스테네스의 체

arr = [True]*10001
arr[0],arr[1] = False,False
for i in range(2,int(10001**0.5)) :
    if arr[i] :
        for j in range(i+i,10001,i) :
            arr[j] = False

T = int(input())

for i in range(T) :
    n = int(input())
    for j in range(n//2) :
        if arr[n//2+j] and arr[n//2-j] :
            print(n//2-j,n//2+j)
            break
