# AC
# 문자열 & 덱 & 파싱

import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

for _ in range(T) :
    p = input().rstrip()
    n = int(input())
    arr = deque(input().rstrip()[1:-1].split(','))
    error = False

    # R 연산이 뜰 때마다 실제 배열을 뒤집는게 아니라 연산이 이루어지는 방향만 바꿈
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