# 문자열 반복
# 문자열

T = int(input())

for i in range(T) :
    inp = input().split()
    N = int(inp[0])
    str = inp[1]
    newStr = ''
    for j in str :
        for l in range(N) :
            newStr+=j
    print(newStr)