# 그룹 단어 체커
# 문자열

N = int(input())
wordList = []
for i in range(N) :
    wordList.append(input())
count = 0
for i in wordList :
    isGroup = True
    letterList = []
    for j in range(len(i)) :
        if i[j] in letterList :
            if i[j] != i[j-1] :
                isGroup = False
        else :
            letterList.append(i[j])
    if isGroup :
        count +=1

print(count)