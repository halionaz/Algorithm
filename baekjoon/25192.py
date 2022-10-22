# 인사성 밝은 곰곰이
# 자료 구조
# 집합과 맵

N = int(input())
users = set()
ans = 0
for _ in range(N) :
    inp = input()
    if inp == "ENTER" :
        users = set()
    else :
        if inp in users :
            continue
        else :
            users.add(inp)
            ans += 1
print(ans)