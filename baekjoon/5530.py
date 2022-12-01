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
arr = [] # I가 써져있는 원판의 인덱스만 따로 저장
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

l = 1
r = len(arr)
# I 기준으로 아래쪽, 원판이 큰 I는 미니 JOIOI 탑의 바닥을 이루는 I이고
# 위쪽, 원판이 작은 I는 탑의 천장을 이룰 것임
# 따라서 I의 어디에서 바닥과 천장을 나눌 것인지가 답을 결정

# 답이 될 수 있는 최댓값은 I의 개수이고, 최솟값은 1

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

print(r)