# 스택 수열
# 스택

n = int(input())
stack = []
arr = []
ans = []
for _ in range(n) : arr.append(int(input()))
j = 0
for i in range(1,n+1) :
    stack.append(i)
    ans.append('+')
    while len(stack) != 0 and arr[j] == stack[-1] :
        stack.pop()
        ans.append('-')
        j += 1
if len(stack) != 0 :
    print('NO')
else :
    for i in ans :
        print(i)