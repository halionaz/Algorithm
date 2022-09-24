# 수 찾기
# 이분 탐색

# 선형 탐색 O(n)

# N = int(input())
# listArr = list(map(int,input().split()))
# M = int(input())
# mapArr = list(map(int,input().split()))
# for i in mapArr :
#     isIn = False
#     for j in listArr :
#         if i == j :
#             print('1')
#             isIn = True
#             break
#     if not isIn :
#         print('0')

# 이진 탐색 O(logN)

N = int(input())
listArr = list(map(int,input().split()))
listArr.sort() # 이진 탐색을 위해서는 배열을 정렬해야 함
M = int(input())
mapArr = list(map(int,input().split()))
for i in mapArr :
    start = 0
    end = N - 1 
    center = (start + end)//2
    isIn = True
    while listArr[center] != i :
        if start > end :
            # 탐색을 모두 했음에도 없음
            print('0')
            isIn = False
            break
        else :
            if listArr[center] < i :
                start = center + 1
                center = (start + end) // 2
            else :
                end = center-1
                center = (start + end) // 2
    if isIn :
        print('1')