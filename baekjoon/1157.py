# 단어 공부
# 문자열

s = input()
count = []
def index_all(l,s) :
    return [index for index, value in enumerate(l) if value == s]

for i in range(26) :
    count.append(0)
for i in s :
    if ord(i)>96 :
        #소문자
        count[ord(i)-97] += 1
    else :
        #대문자
        count[ord(i)-65] += 1
if len(index_all(count,max(count))) == 1 :
    print(chr(65+count.index(max(count))))
else :
    print('?')

