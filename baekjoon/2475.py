# 검증수
# 사칙연산

inp = list(map(int,input().split()))

sum = 0
for i in inp :
    sum += pow(i,2)
print(sum%10)