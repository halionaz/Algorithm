# 숫자의 개수
# 사칙연산 & 구현

count = [0,0,0,0,0,0,0,0,0,0]
inp = []
for i in range(3) : 
    inp.append(int(input()))
num = inp[0]*inp[1]*inp[2]

for i in str(num) :
    count[int(i)]+=1

for i in count :
    print(i)