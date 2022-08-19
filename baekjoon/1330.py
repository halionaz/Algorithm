# 두 수 비교하기
# 구현

inp = input().split()
A, B = int(inp[0]),int(inp[1])

if A>B :
    print('>')
elif A<B :
    print('<')
else :
    print('==')