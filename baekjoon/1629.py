# 곱셈
# 분할 정복을 이용한 거듭제곱

A,B,C = map(int,input().split())

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