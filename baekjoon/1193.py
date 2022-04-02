# 분수찾기
# 수학 & 구현

X = int(input())
i = 0
sum = 0
while sum<X :
    i += 1
    sum += i
num = X-(sum-i)
if i%2 == 0 :
    print("{}/{}".format(num,i-num+1))
else :
    print("{}/{}".format(i-num+1,num))
