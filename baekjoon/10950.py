# A+B - 3
# 사칙연산

T = int(input())

inp = []
for i in range(T) :
    inp.append(input().split())

for i in inp :
    print(int(i[0])+int(i[1]))
