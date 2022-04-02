# 좌표 정렬하기
# 정렬

# N = int(input())
# arr = []
# for _ in range(N) :
#     arr.append(list(map(int,input().split())))
# arr.sort()
# for i in arr :
#     print(i[0],i[1])

import sys
N = int(sys.stdin.readline())
arr = []
for _ in range(N) :
    arr.append(list(map(int,sys.stdin.readline().split())))
arr.sort()
for i in arr :
    print(i[0],i[1])

# 왜인지 안 먹힌다 - 시간초과
# import sys
# N = int(sys.stdin.readline())
# arr = []
# for _ in range(N) :
#     arr.append(list(map(int,sys.stdin.readline().split())))
# for i in range(N-1) :
#     for j in range(N-1-i) :
#         if arr[j][0] > arr[j+1][0] :
#             arr[j], arr[j+1] = arr[j+1],arr[j]
#         elif arr[j][0] == arr[j+1][0] :
#             if arr[j][1] > arr[j+1][1] :
#                 arr[j], arr[j+1] = arr[j+1],arr[j]
# for i in arr :
#     print(i[0],i[1])