# 수 정렬하기 2
# 정렬

# Python Sort

# N = int(input())
# arr = []
# for _ in range(N) :
#     arr.append(int(input()))
# for i in sorted(arr) :
#     print(i)

# Merge Sort
def merge(leftList, rightList):
    li = 0
    ri = 0
    returnList = []
    while li < len(leftList) and ri < len(rightList):
        if leftList[li] < rightList[ri]:
            returnList.append(leftList[li])
            li += 1
        else:
            returnList.append(rightList[ri])
            ri += 1
    if li != len(leftList):
        for i in range(li, len(leftList)):
            returnList.append(leftList[i])
    elif ri != len(rightList):
        for i in range(ri, len(rightList)):
            returnList.append(rightList[i])
    return returnList


def mergeSort(arr):
    if len(arr) == 1:
        return arr
    else:
        mid = len(arr)//2
        return merge(mergeSort(arr[:mid]), mergeSort(arr[mid:]))


N = int(input())
arr = []
for i in range(N):
    arr.append(int(input()))
for i in mergeSort(arr):
    print(i)
