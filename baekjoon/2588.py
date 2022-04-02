# 곱셈
# 사칙연산

i1 = int(input())
i2 = int(input())
print(i1*(i2%10))
print(i1*(i2//10%10))
print(i1*(i2//100))
print(i1*(i2%10)+i1*(i2//10%10)*10+i1*(i2//100)*100)