# 배수와 약수
# 사칙연산

while 1 :
    a,b = map(int,input().split())
    if a==0 and b==0 :
        break
    elif a>b and a%b==0 :
        print('multiple')
    elif a<b and b%a==0 :
        print('factor')
    else :
        print('neither')