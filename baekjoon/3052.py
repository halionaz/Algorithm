# 나머지
# 사칙연산

kind = []

for i in range(10) :

    inp = int(input())%42

    if inp not in kind :
        kind.append(inp)

print(len(kind))