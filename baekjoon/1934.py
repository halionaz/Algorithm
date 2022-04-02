# 최소공배수
# 유클리드 호제법 & 정수론

T = int(input())
for _ in range(T) :
    a,b = map(int,input().split())
    mult = a*b
    if b>a :
        a, b = b, a
    while b != 0 :
        temp = a%b
        a = b
        b = temp
    print(mult//a)
