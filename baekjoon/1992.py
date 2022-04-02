# 쿼드트리
# 분할 정복

N = int(input())
arr = []
for _ in range(N) : arr.append(list(map(int,input())))
ans = ''

def compress(x,y,n) :
    global ans
    cnt_0 = 0
    cnt_1 = 0
    for i in range(y,y+n) :
        for j in range(x,x+n) :
            if arr[i][j] == 0 : 
                cnt_0 += 1
            else :
                cnt_1 += 1
    if cnt_0 == n**2 :
        ans += '0'
    elif cnt_1 == n**2 :
        ans += '1'
    else :
        ans += '('
        compress(x, y, n//2)
        compress(x + n//2, y, n//2)
        compress(x, y + n//2, n//2)
        compress(x + n//2, y + n//2, n//2)
        ans += ')'

compress(0, 0, N)
print(ans)