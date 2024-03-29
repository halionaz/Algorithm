# 계단 오르기
# 다이나믹 프로그래밍
# bottom-up

N = int(input())
arr = []
for _ in range(N) :
    arr.append(int(input()))
if N > 2 :
    # sumArr[i][0] :: i-3번째 계단과 i-1번째 계단을 밟았을 때의 최대 점수 
    # sumArr[i][1] :: i-2번째 계단과 i-1번째 계단을 밟았을 때의 최대 점수
    sumArr = [0, arr[0], [arr[1],arr[0]+arr[1]] ,[arr[0]+arr[2],arr[1]+arr[2]]]
    for i in range(4,N+1) :
        # sumArr[i][0] = max(sumArr[i-2][0] + arr[i-1], sumArr[i-2][1] + arr[i-1])
        # sumArr[i][1] = sumArr[i-1][0] + arr[i-1]
        sumArr.append([max(sumArr[i-2][0],sumArr[i-2][1])+arr[i-1],sumArr[i-1][0]+arr[i-1]])
    print(sorted(sumArr[N])[-1])
elif N == 1:
    print(arr[0])
else :
    print(arr[0]+arr[1])