# 대칭 차집합
# 자료 구조
# 집합과 맵

import sys
input = sys.stdin.readline
_ = input()
A = set(map(int, input().split()))
B = set(map(int, input().split()))

print(len(A-B) + len(B-A))