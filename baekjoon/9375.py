# 패션왕 신해빈
# 조합론

T = int(input())

for _ in range(T) :
    n = int(input())
    kindArr = []
    numArr = []
    for i in range(n) :
        name,kind = input().split()
        if kind in kindArr :
            numArr[kindArr.index(kind)] += 1
        else :
            kindArr.append(kind)
            numArr.append(1)
    ans = 1
    for i in numArr :
        ans *= i+1
    print(ans-1) # 알몸인 상태만 제외