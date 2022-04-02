# 포도주 시식
# 다이나믹 프로그래밍

n = int(input())
arr = []
for _ in range(n) :
    arr.append(int(input()))
memo = [[arr[0],arr[0]]]
for i in range(1,n) :
    if i == 1 :
        memo.append([arr[1],memo[0][0]+arr[1]])
    elif i == 2:
        memo.append([max(memo[i-2][0],memo[i-2][1])+arr[i],memo[i-1][0]+arr[i]])
    else :
        memo.append([max(memo[i-2][0],memo[i-2][1],memo[i-3][0],memo[i-3][1])+arr[i],memo[i-1][0]+arr[i]])
if n == 1:
    print(arr[0])
else :
    print(max(memo[-1][0], memo[-1][1],memo[-2][0],memo[-2][1]))

# 얘도 슬라이딩 윈도 기법 만들 수 있을 것 같다