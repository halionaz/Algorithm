# 나머지
# 사칙연산

inp = input().split()
A,B,C=int(inp[0]),int(inp[1]),int(inp[2])

print((A+B)%C)
print(((A%C) + (B%C))%C)
print((A*B)%C)
print(((A%C)*(B%C))%C)