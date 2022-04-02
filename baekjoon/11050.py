# 이항 계수 1
# 조합론

N,K = map(int,input().split())
ans = 1
for i in range(K) :
    ans*=N
    ans/=i+1
    N -= 1;
print(int(ans))

# #재귀함수
# def fact(N) :
#     if N == 1 or N == 0 :
#         return 1
#     else :
#         return fact(N-1)*N

# N,K = map(int,input().split())
# print(int(fact(N)/(fact(N-K)*fact(K))))