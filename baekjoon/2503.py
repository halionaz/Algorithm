# 숫자 야구
# 브루트포스 알고리즘

def baseball(arr,a,b,c):
    strike = 0
    ball = 0
    string = str(arr[0])
    if str(a) in string : #첫자리가 있으면
        if string[0] == str(a) : #같은 자리인지 확인
            strike += 1
        else :
            ball += 1
    if str(b) in string :
        if string[1] == str(b) :
            strike += 1
        else :
            ball += 1
    if str(c) in string :
        if string[2] == str(c) :
            strike += 1
        else :
            ball += 1
    if arr[1] == strike and arr[2] == ball : #스트라이크랑 볼이랑 같으면 조건 만족 
        return True
    else :
        return False

N = int(input())
arr = []
for _ in range(N) :
    arr.append(list(map(int,input().split())))
ans = []
for i in range(1,10) :
    for j in range(1,10) :
        if j != i : # '다 다른 숫자' 여야 함
            for l in range(1,10) :
                if l != i and l!=j :
                    isRight = True
                    for m in arr :
                        if not baseball(m, i, j, l) : #각 조건과 첫째자리, 둘째자리, 셋째자리 비교
                            isRight = False
                            break
                    if isRight : #모든 조건을 충족하는 수만 ans 배열에 저장
                        ans.append(i*100+j*10+l)
print(len(ans)) #정답 배열의 길이
