# 평균
# 수학 & 사칙연산

N = int(input())
arr = list(map(int,input().split()))
newArr = []
highest = arr[0]
for i in arr :
    if i > highest :
        highest = i
for i in range(len(arr)) :
    newArr.append(arr[i]/highest*100)


print(sum(newArr)/len(newArr))