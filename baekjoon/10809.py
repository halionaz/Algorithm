# 알파벳 찾기
# 문자열

s = input()
answer = ''
for i in range(26) :
    if chr(i+97) in s :
        answer += str(s.index(chr(i+97)))+' '
    else :
        answer += '-1 '
print(answer)