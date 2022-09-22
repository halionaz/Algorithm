# 좌표 압축
# 값 / 좌표 압축 & 정렬
# py_output_at_once

# 일일이 카운트 -> 좆망
# import sys
# N = int(sys.stdin.readline())
# arr = list(map(int,sys.stdin.readline().split()))
# kindArr = []
# for i in kindArr :
# ans = []
# for i in arr :
#     cnt = 0
#     for j in arr : 
#         if j < i :
#             cnt += 1
#     ans.append(str(cnt))
# print(' '.join(ans))

# 야매식
# import sys
# N = int(sys.stdin.readline())
# arr = list(map(int,sys.stdin.readline().split()))
# kindArr = list(sorted(set(arr)))
# ans = []
# for i in arr :
#     cnt = 0
#     for j in kindArr :
#         if j < i :
#             cnt += 1
#     ans.append(str(cnt))
# print(' '.join(ans))

# pythonic way
import sys
input = sys.stdin.readline

N = int(input())
X = list(map(int, input().split()))

# 중복된 수 없이 정렬
Xset = list(sorted(set(X)))

Xset={Xset[i] : i for i in range(len(Xset))}
# 정렬된 리스트의 인덱스가 그 항목의 좌표압축값임, 이를 딕셔너리로 저장
print(*[Xset[i] for i in X])
# x를 기준으로 for문을 돌려 i를 딕셔너리에 넣어 값을 확인하고, 이를 배열로 저장한 후 *를 이용해 한번에 프린트
