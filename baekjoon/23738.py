# Ресторан
# 구현

# 2021 서강 프로그래밍 콘테스트 A번 문제

S = input()
ans = ''
for i in S :
    if i == 'A' :
        ans += 'a'
    elif i == 'B' :
        ans += 'v'
    elif i == 'E' :
        ans += 'ye'
    elif i == 'K' :
        ans += 'k'
    elif i == 'M' :
        ans += 'm'
    elif i == 'H' :
        ans += 'n'
    elif i == 'O' :
        ans += 'o'
    elif i == 'P' :
        ans += 'r'
    elif i == 'C' :
        ans += 's'
    elif i == 'T' :
        ans += 't'
    elif i == 'Y' :
        ans += 'u'
    elif i == 'X' :
        ans += 'h'
print(ans)