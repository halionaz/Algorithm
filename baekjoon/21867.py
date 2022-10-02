# Java Bitecode
# 구현 & 문자열

N = int(input())
S = input()
javaBitecode = ''
for i in S :
    if i != 'J' and i !='A' and i != 'V' :
        javaBitecode += i
if len(javaBitecode) :
    print(javaBitecode)
else :
    print('nojava')