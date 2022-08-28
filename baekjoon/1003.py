# 피보나치 함수
# 다이나믹 프로그래밍

T = int(input())
for _ in range(T) :
    N = int(input())
    zero = [1,0]
    one = [0,1]
    if N < 2 :
        print(zero[N],one[N])
    else :
        for i in range(2,N+1) :
            zero.append(zero[i-1]+zero[i-2])
            one.append(one[i-1]+one[i-2])
        print(zero[N],one[N])