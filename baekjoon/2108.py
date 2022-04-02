# 통계학
# 정렬

import sys
N = int(sys.stdin.readline())
arr = []
dic = {}
for i in range(N) :
    inp = int(sys.stdin.readline())
    arr.append(inp)
    if inp in dic.keys() :
        dic[inp] += 1
    else :
        dic[inp] = 1
print(round(sum(arr)/N))
arr.sort()
print(arr[N//2])
sortDic = sorted(dic.items(),key=lambda x: x[1])
max = sortDic[-1][1]
for i in range(len(sortDic)) :
    if sortDic[i][1] == max :
        sortArr = sorted(sortDic[i:])
        if len(sortArr) == 1 :
            print(sortArr[0][0])
            break
        else :
            print(sortArr[1][0])
            break
print(arr[-1]-arr[0])


