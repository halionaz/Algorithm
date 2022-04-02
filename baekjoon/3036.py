# 링
# 유클리드 호제법 & 수학

# math 라이브러리 사용 X

def gcd(a,b) :
    if a<b :
        a,b = b,a
    if b==0 : 
        return a
    else :
        return gcd(b,a%b)
N = int(input())
arr = list(map(int, input().split()))
for i in range(1,N) :
    g = gcd(arr[0], arr[i])
    print('{}/{}'.format(arr[0]//g,arr[i]//g))

# math 라이브러리 사용 O

# import math
# N = int(input())
# arr = list(map(int, input().split()))
# for i in range(1,N) :
#     g = math.gcd(arr[0], arr[i])
#     print('{}/{}'.format(arr[0]//g,arr[i]//g))