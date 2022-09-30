# 통계학
# 정렬

import sys
N = int(sys.stdin.readline())
arr = []
dic = {} # 최빈값을 구하기 위한 dictionary
for i in range(N) :
    inp = int(sys.stdin.readline())
    arr.append(inp)
    if inp in dic.keys() :
        dic[inp] += 1
    else :
        dic[inp] = 1
print(round(sum(arr)/N)) # 산술평균
arr.sort()
print(arr[N//2]) # 중앙값
sortDic = sorted(dic.items(),key=lambda x: x[1])
max = sortDic[-1][1]
for i in range(len(sortDic)) :
    if sortDic[i][1] == max :
        sortArr = sorted(sortDic[i:])
        if len(sortArr) == 1 :
            # 최빈값이 하나라면 그것을 출력
            print(sortArr[0][0])
            break
        else :
            # 최빈값이 두개 이상이면 두번째로 작은 값 출력
            print(sortArr[1][0])
            break
print(arr[-1]-arr[0])


