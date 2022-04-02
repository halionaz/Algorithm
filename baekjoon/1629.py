# 곱셈
# 분할 정복을 이용한 거듭제곱

A,B,C = map(int,input().split())

# #for문으로 구현
# ans = 1
# for _ in range(B) :
#     ans *= A
#     ans %= C
# print(ans)

# #재귀함수로 구현
# def multiple(b) :
#     if b == 0 :
#         return 1
#     else :
#         return (multiple(b-1)*A)%C
# print(multiple(B))

#분할 정복으로 구현
def multiple(n) :
    if n == 1:
        return A % C
    else :
        if n%2 == 0 :
            return (multiple(n//2)**2)%C
        else :
            return ((multiple(n//2)**2)*A)%C
print(multiple(B))

# #파이썬 기본 함수로 구현
# print(pow(A,B,C))