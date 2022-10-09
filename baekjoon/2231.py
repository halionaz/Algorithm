# 분해합
# 브루트포스 알고리즘

N = int(input())

def T(n):
    # 분해합을 구해주는 함수
    strN = str(n)
    sum = 0
    for i in strN :
        sum += int(i)
    return sum+n

noAnswer = True
for i in range(N) :
    if T(i) == N :
        print(i)
        noAnswer = False
        break
if noAnswer :
    print(0)