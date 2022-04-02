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

# 괜히 재귀함수 써보려다 말음
# def fibo(n) :
#     if n == 0 :
#         return [1,0]
#     elif n == 1 :
#         return [0,1]
#     else :
#         fib1,fib2 = fibo(n-1),fibo(n-2)
#         return [fib1[0]+fib2[0],fib1[1]+fib2[1]]

# for _ in range(T) :
#     N = int(input())
#     print(' '.join(map(str,fibo(N))))