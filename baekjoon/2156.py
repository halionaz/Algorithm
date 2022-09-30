# 포도주 시식
# 다이나믹 프로그래밍
# bottom-up

n = int(input())
arr = []
for _ in range(n) :
    arr.append(int(input()))

# memo[i][0] :: i-1번째 와인을 마시지 않았고, i번째 와인을 마시는 경우 최대로 마실 수 있는 와인양
# memo[i][1] :: i-1번째 와인을 마셨고, i번째 와인을 마시는 경우 최대로 마실 수 있는 와인양
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