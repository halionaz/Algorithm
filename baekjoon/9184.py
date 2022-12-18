# 신나는 함수 실행
# 다이나믹 프로그래밍 & 재귀
# top-down

memo = [[[0]*21 for i in range(21)] for j in range(21)]

def w(a,b,c) :
    if a<=0 or b<=0 or c<=0 :
        return 1
    elif a>20 or b>20 or c>20 :
        return w(20,20,20)

    if not memo[a][b][c] :
        if a < b and b < c :
            memo[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        else :
            memo[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

    return memo[a][b][c]

while 1 :
    a,b,c = map(int,input().split())
    if a==-1 and b==-1 and c==-1 :
        break
    print("w({}, {}, {}) = {}".format(a,b,c,w(a,b,c)))