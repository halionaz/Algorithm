# 수 정렬하기 3
# 정렬

#Counting Sort

# import sys
# N = int(sys.stdin.readline())
# arr = []
# max = 0
# for _ in range(N) :
#     inp = int(sys.stdin.readline())
#     arr.append(inp)
#     if inp > max :
#         max = inp
# count = [0]*max
# for i in arr :
#     count[i-1] += 1
# for i in range(len(count)) :
#     if i != 0 :
#         count[i] += count[i-1]
# answer = [None]*N
# for i in reversed(arr) :
#     answer[count[i-1]-1] = i
#     count[i-1] -= 1
# for i in answer :
#     print(i)

import sys
n = int(sys.stdin.readline())
b = [0] * 10001
for i in range(n):
    b[int(sys.stdin.readline())] += 1
for i in range(10001):
    if b[i] != 0:
        for j in range(b[i]):
            print(i)

#Python Sort

# import sys
# N = int(sys.stdin.readline())
# arr = []
# for _ in range(N) :
#     arr.append(int(sys.stdin.readline()))
# for i in sorted(arr) :
#     print(i)