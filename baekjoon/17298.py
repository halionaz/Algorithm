# 오큰수
# 스택

#스택 미사용
# import sys
# input = sys.stdin.readline
# N = int(input())
# stack = list(map(int, input().split()))
# answer = []
# for i in range(N) :
#     if i == N-1 :
#         answer.append('-1')
#     else :
#         ans = False
#         for j in range(i+1,N) :
#             if stack[j] > stack[i] :
#                 ans = True
#                 answer.append(str(stack[j]))
#                 break
#         if not ans :
#             answer.append('-1')
# print(' '.join(answer))

#스택 사용
import sys
input = sys.stdin.readline
N = int(input())
arr = list(map(int, input().split()))
ans = [-1]*N
stack = []
for i in range(N) :
    #와일문으로 지금까지 쌓였던 같은답 스택들 제거
    while len(stack) != 0 and arr[stack[-1]] < arr[i] :
        ans[stack[-1]] = arr[i]
        stack.pop()
    stack.append(i)
print(' '.join(map(str,ans)))