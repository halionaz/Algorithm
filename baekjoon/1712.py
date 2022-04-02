# 손익분기점
# 수학 & 사칙연산

# import sys
# inp = sys.stdin.readline().strip().split()
# A,B,C = int(inp[0]),int(inp[1]),int(inp[2])
# i = 0
# if C <= B :
#     print(-1)
# else : 
#     while A + B*i >= C*i :
#         i += 1
#     print(i)
    
inp = list(map(int,input().split()))
A,B,C = inp[0],inp[1],inp[2]
if C <= B :
    print(-1)
else :
    profit = C-B
    print(A//profit+1)