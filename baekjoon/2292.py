# 벌집
# 수학

# 1 :: 1 :: 1
# 2-7 :: 2 :: 6
# 8-19 :: 3 :: 12
# 20-37 :: 4 :: 18
# 38-61 :: 5 :: 24

N = int(input())

ans = 1
for i in range(N) :
    ans += i * 6
    if N <= ans :
        break

print(i+1)