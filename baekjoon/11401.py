# 이항 계수 3
# 페르마의 소정리 & 분할 정복을 이용한 거듭제곱 & 정수론 & 조합론 & 수학 & 모듈로 곱셈 역원

# 페르마의 소정리 사용
# N!%p*((K!(N-K)!)^(p-2)) %p

N,K = map(int, input().split())
def square(a,b) :
    if b == 0 :
        return 1
    elif b == 1 :
        return a % 1000000007
    else :
        if b % 2 == 0 :
            return (square(a, b//2)**2) % 1000000007
        else :
            return (square(a, b//2)**2)*a % 1000000007
n = 1
nk = 1
# N! 구해주는 단계
for i in range(1,N+1) :
    n *= i
    n %= 1000000007
# K! 구해주는 단계
for i in range(1, K+1) :
    nk *= i
    nk %= 1000000007
# K!*(N-K)! 구해주는 단계
for i in range(1, N-K+1) :
    nk *= i
    nk %= 1000000007
nk = square(nk, 1000000005)
print((n*nk)%1000000007)


# #POW 함수 사용 

# N,K = map(int, input().split())
# n = 1
# nk = 1
# for i in range(1,N+1) :
#     n *= i
#     n %= 1000000007
# for i in range(1, K+1) :
#     nk *= i
#     nk %= 1000000007
# for i in range(1, N-K+1) :
#     nk *= i
#     nk %= 1000000007
# nk = pow(nk, 1000000005, 1000000007)
# print((n*nk)%1000000007)