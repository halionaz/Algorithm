# 팩토리얼 0의 개수
# 임의 정밀도 / 큰 수 연산

N = int(input())
two = five = 0
for i in range(1,N+1) :
    if i%5 == 0 :
        n = i
        while n % 5 == 0 :
            five += 1
            n //= 5
    if i%2 == 0 :
        n = i
        while n % 2 == 0 :
            two += 1
            n //= 2
print(min(two, five))