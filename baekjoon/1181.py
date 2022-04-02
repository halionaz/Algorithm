# 단어 정렬 
# 문자열

import sys
N = int(sys.stdin.readline())
arr = []
for _ in range(N) :
    inp = sys.stdin.readline().rstrip()
    if inp not in arr :
        arr.append(inp)
arr.sort()
arr.sort(key=len)
for i in arr :
    print(i)