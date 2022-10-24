# 최대공약수와 최소공배수
# 유클리드 호제법

a,b = map(int,input().split())
if b > a :
    a, b = b, a
ans = 0
aArr = []
i = 1
while 1 :
    aArr.append(a*i)
    if b*i in aArr :
        ans = b*i
        break
    i += 1

while b != 0 :
    temp = a%b
    a = b
    b = temp

print(a)
print(ans)
