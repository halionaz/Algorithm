# 상수
# 수학 & 문자열 & 구현

inp = input().split()
# 뒤집기
A = int(inp[0][::-1])
B = int(inp[1][::-1])

if A > B :
    print(A)
else :
    print(B)