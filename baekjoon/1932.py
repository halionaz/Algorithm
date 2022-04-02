# 정수 삼각형
# 다이나믹 프로그래밍

n = int(input())
arr = []
for _ in range(n) :
    arr.append(list(map(int,(input().split()))))
sumArr = [arr[0]]
for i in range(1,n) :
    stage = []
    for j in range(i+1) :
        if j == 0 :
            stage.append(sumArr[i-1][0]+arr[i][0])
        elif j == i :
            stage.append(sumArr[i-1][j-1]+arr[i][j])
        else :
            stage.append(max(sumArr[i-1][j-1], sumArr[i-1][j])+arr[i][j])
    sumArr.append(stage)
print(sorted(sumArr[-1])[-1])