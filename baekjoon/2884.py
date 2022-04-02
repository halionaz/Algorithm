# 알람 시계
# 사칙연산

inp = input().split()
H = int(inp[0])
M = int(inp[1])

if M-45 < 0 :
    #코드작성
    if H-1 < 0 :
        print(H+23,M+15)
    else :
        print(H-1,15+M)
else :
    print(H,M-45)