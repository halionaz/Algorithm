# 집합
# 비트마스킹

# List 

# import sys
# input = sys.stdin.readline
# M = int(input())
# S = [0]*21
# for _ in range(M) :
#     inp = input().rstrip().split()
#     if inp[0] == 'add' :
#         S[int(inp[1])] = 1
#     elif inp[0] == 'remove' :
#         S[int(inp[1])] = 0
#     elif inp[0] == 'check' :
#         print(S[int(inp[1])])
#     elif inp[0] == 'toggle' :
#         i = int(inp[1])
#         if S[i] :
#             S[i] = 0
#         else :
#             S[i] = 1
#     elif inp[0] == 'all' :
#         for i in range(1,21) :
#             S[i] = 1
#     else :
#         for i in range(1,21) :
#             S[i] = 0

# Set

# import sys
# input = sys.stdin.readline
# M = int(input())
# S = set()
# for _ in range(M) :
#     inp = input().rstrip().split()
#     if inp[0] == 'add' :
#         S.add(int(inp[1]))
#     elif inp[0] == 'remove' :
#         S.discard(int(inp[1]))
#     elif inp[0] == 'check' :
#         if int(inp[1]) in S :
#             print(1)
#         else :
#             print(0)
#     elif inp[0] == 'toggle' :
#         i = int(inp[1])
#         if i in S :
#             S.remove(i)
#         else :
#             S.add(i)
#     elif inp[0] == 'all' :
#         S = set(range(1,21))
#     else :
#         S = set()

# 비트마스킹
# 비트로 위 리스트 알고리즘 구현

import sys
input = sys.stdin.readline
M = int(input())
S = 0
for _ in range(M) :
    inp = input().rstrip().split()
    if inp[0] == 'add' :
        S = S|(1<<int(inp[1])-1)
    elif inp[0] == 'remove' :
        S = S&~(1<<int(inp[1])-1)
    elif inp[0] == 'check' :
        if S&(1<<int(inp[1])-1) :
            print(1)
        else :
            print(0)
    elif inp[0] == 'toggle' :
        S = S^(1<<int(inp[1])-1)
    elif inp[0] == 'all' :
        S = 0b11111111111111111111
    else :
        S = 0