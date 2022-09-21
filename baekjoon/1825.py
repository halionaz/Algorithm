# 순열 만들기
# 그리디 알고리즘 & 구성적

import sys
input = sys.stdin.readline
N, M, K = map(int, input().split())
if N < M + K - 1 or N > M * K : 
    # 만족하는 경우가 존재하지 않음
    print(-1)
else :
    arr1 = []
    arr2 = []
    for i in range(1,N+1) :
        # 하나는 순차대로, 하나는 역순으로 저장
        arr1.append(i)
        arr2.append(N-i+1)
    # 1201 문제와 다르게, 사전 순으로 가장 앞서는 것과 가장 나중의 것 두개를 출력해야 함

    # 최대 K개의 숫자를 내림차순으로 하는 수열 M개를 이어 붙이면
    # 가장 긴 감소하는 부분 수열의 길이는 K이면서
    # 가장 긴 증가하는 부분 수열의 길이는 M이 됨
    ind = N
    # M개의 수열 제작
    for i in range(1, M+1) :
        # ind에서 K만큼 빼준 값과, 남은 M개의 그룹을 만들 수 있을만큼의 값을 남긴 것중 큰 것 선택
        start = max(ind - K, M - i)
        arr1[start:ind] = reversed(arr1[start:ind])
        ind = start

    # 한편 역순 상태에서 최대 M개의 숫자를 오름차순으로 하는 수열 K개를 이어 붙여도
    # 가장 긴 감소하는 부분 수열의 길이는 K이면서
    # 가장 긴 증가하는 부분 수열의 길이는 M이 됨
    ind = N
    # K개의 수열 제작
    for i in range(1,K+1) :
        # ind에서 M만큼 빼준 값과, 남은 K개의 그룹을 만들 수 있을만큼의 값을 남긴 것중 큰 것 선택
        start = max(ind - M, K - i)
        arr2[start:ind] = reversed(arr2[start:ind])
        ind = start
    print(' '.join(map(str,arr1)))
    print(' '.join(map(str,arr2)))