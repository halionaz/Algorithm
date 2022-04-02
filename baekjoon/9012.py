# 괄호
# 문자열 & 스택

# 스택으로 구현
T = int(input())
for _ in range(T) :
    inp = input()
    stack = []
    isVPS = True
    for i in inp :
        if i == '(' :
            stack.append(1)
        else :
            if len(stack) == 0 :
                isVPS = False
                break
            else :
                stack.pop()
    if len(stack) == 0 and isVPS :
        print('YES')
    else :
        print('NO')

# # 백서경

# T = int(input())
# for _ in range(T) :
#     S = list(input())
#     testdata = S + [0]*(51-len(S))
#     cnt1 = cnt2 = 0
#     j = 0
#     while testdata[j] != 0 :
#         if testdata[j] == '(' :
#             cnt1 += 1
#             j += 1
#         elif testdata[j] == ')' :
#             cnt2+=1
#             j += 1

#     k = 0
#     while(k < len(S)) :
#         if testdata[k] == '(' and testdata[k+1] == ')' :
#             l = k
#             while testdata[l] != 0 :
#                 testdata[l] = testdata[l+2]
#                 l += 1
#             k -= 1
#         k+=1

#     s = 0
#     while testdata[s] != 0 :
#         s += 1
#     s = s - 1
#     if s == -1 :
#         s = 0;

#     if testdata[0] == ')' :
#         print('NO')
#     elif testdata[s] == '(' :
#         print('NO')
#     elif cnt1 != cnt2 :
#         print('NO')
#     else :
#         print('YES')