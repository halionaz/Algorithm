# N과 M (5)
# 백트래킹
# py_output_at_once

import sys
input = sys.stdin.readline
N,M = map(int,input().split())
numList = []
numList = list(map(int,input().split()))
numList.sort()
arr = [0]*M
def dfs(depth) :
    if depth == M :
        print(*arr)
        return
    else :
        for i in numList :
            if i not in arr :
                arr[depth] = i
                dfs(depth+1)
                arr[depth] = 0
    return
dfs(0)