# JOIOI 탑
# 이분 탐색 & 매개 변수 탐색

# 아직 이분 탐색 개념을 잘 모르겠어서
# 직접 디버깅 하면서 알아보고 있다
# 이 문제는 특히 더 어려운 것 같기도..

# arr에는 끝이 될 수 있는 I만 저장
# JOI 또는 IOI가 되려면 무조건 I로 끝내야 함

# can_be 함수는 끝에 x가 I가 끝나는 I일 때 성립하는지 체크
# 끝나는 I의 개수가 1~len(arr) 중 하나일테니 (만약 0이면 답을 찾지 못한 채 ans = 0 으로 끝)
# 이분 탐색을 해 나감

# python은 너무 느리다 pypy3으로 제출 성공

import sys
input = sys.stdin.readline
N = int(input())
S = input().rstrip();
arr = []
for ind, c in enumerate(S) :
    if c == 'I' :
        arr.append(ind)

def can_be(x) :
    limit = arr[len(arr) - x] # 이 index부턴 끝나는 I
    start = mid = end = 0
    for i in range(N) :
        if S[i] == 'I' and i < limit :
            start += 1 # 'I'OI
        elif S[i] == 'J' :
            start += 1 # 'J'OI
        elif S[i] == 'O' and start > 0 :
            mid += 1
            start -= 1 
        elif S[i] == 'I' and mid > 0 and i >= limit :
            mid -= 1
            end += 1
    return x == end

ans = 0

l = 1
r = len(arr)

while l <= r :
    limit = (l + r)//2
    if can_be(limit) :
        # 이 끝나는 I 개수가 만족됐다면 끝 I 개수를 더 줄여볼 수 있음
        # 따라서 끝나는 I 인덱스를 올려 이분 탐색
        ans = limit
        l = limit + 1
    else : 
        # 만족하는 경우가 없으므로 끝 I 개수 늘리기
        r = limit - 1

print(ans)