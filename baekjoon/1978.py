# 소수 찾기
# 소수 판정 & 에라토스테네스의 체

N = int(input())
inp = list(map(int,input().split()))

count = 0
for i in range(N) :
    isDecimal = True
    for j in range(inp[i]) :
        if (j!=0 and j!=1 and inp[i]%j == 0) or inp[i]==1:
            isDecimal = False
            break
    if isDecimal :
        count += 1
print(count)