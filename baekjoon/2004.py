# 조합 0의 개수
# 수학 & 정수론

# #nCm은 n!을 n-m!과 m!로 나눈 것.

# N,M = map(int,input().split())
# two = five = 0
# for i in range(1,N+1) :
#     if i%5 == 0 :
#         n = i
#         while n % 5 == 0 :
#             five += 1
#             n //= 5
#     if i%2 == 0 :
#         n = i
#         while n % 2 == 0 :
#             two += 1
#             n //= 2
# for i in range(1,N-M+1) :
#     if i%5 == 0 :
#         n = i
#         while n % 5 == 0 :
#             five -= 1
#             n //= 5
#     if i%2 == 0 :
#         n = i
#         while n % 2 == 0 :
#             two -= 1
#             n //= 2
# for i in range(1,M+1) :
#     if i%5 == 0 :
#         n = i
#         while n % 5 == 0 :
#             five -= 1
#             n //= 5
#     if i%2 == 0 :
#         n = i
#         while n % 2 == 0 :
#             two -= 1
#             n //= 2
# ans = min(two,five)
# print(ans)

# nCm은 n!을 n-m!과 m!로 나눈 것.

def countNum(N, num) :
    count = 0
    div = num
    while( N >= div) :
        count += N // div
        div *= num
    return count
n,m = map(int,input().split())

# 2의 개수와 5의 개수 중 최솟값이 10이 곱해진 횟수
ans = min(countNum(n,5)-countNum(n-m,5)-countNum(m, 5),countNum(n, 2)-countNum(n-m, 2)-countNum(m, 2))
print(ans)