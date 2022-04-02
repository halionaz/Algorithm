# 달팽이는 올라가고 싶다
# 수학

inp = list(map(int,input().split()))

A = inp[0]
B = inp[1]
V = inp[2]

if (V-A)%(A-B) == 0:
    print((V-A)//(A-B)+1)
else :
    print((V-A)//(A-B)+2)