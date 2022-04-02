# AC
# 문자열 & 덱

import sys
from collections import deque
input = sys.stdin.readline
T = int(input())
for _ in range(T) :
    p = input().rstrip()
    n = int(input())
    arr = deque(input().rstrip()[1:-1].split(','))
    error = False
    reverse = False
    if arr[0] == '' :
        del arr[0]
    for i in p :
        if i == 'R' :
            reverse = not reverse
        else :
            if len(arr) == 0:
                error = True
                break
            else :
                if reverse :
                    arr.pop()
                else :
                    arr.popleft()
    if not error :
        if reverse :
            print('['+','.join(reversed(arr))+']')
        else :
            print('['+','.join(arr)+']')
    else :
        print('error')