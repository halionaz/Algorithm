# X보다 작은 수
# 구현

inp1 = input().split()
N = int(inp1[0])
X = int(inp1[1])

inp2 = input().split()

ans = ''
for i in range(N) :
    if int(inp2[i])<X :
        ans += inp2[i] + ' '
print(ans)