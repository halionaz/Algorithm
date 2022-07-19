# 나이순 정렬
# 정렬

# python은 정렬을 timsort를 쓰기에 stable(같은 요소의 경우 원래 순서를 유지)함
# 이를 이용한 풀이

import sys

N = int(sys.stdin.readline())
arr = []
for i in range(N) :
    inp = sys.stdin.readline().split()
    arr.append([int(inp[0]),inp[1]])
arr.sort(key = lambda x: x[0])
for i in arr :
    print(i[0],i[1])