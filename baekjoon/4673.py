# 셀프 넘버
# 브루트포스 알고리즘

# num = []
# for i in range(10000) :
#     num.append(i+1)

# for i in range(10000):
#     strI = str(i+1) #각각의 숫자를 계산하기 위해 str로 형변환
#     sumOfNum = 0
#     for j in strI :
#         sumOfNum += int(j)
#     d = i+1 + sumOfNum #D값
#     try:
#         num.remove(d)
#     except:
#         pass

# for i in num :
#     print(i)

def d(n) :
    strN = str(n)
    sum = n
    for i in strN :
        sum += int(i)
    return sum

num = []
for i in range(10000) :
    num.append(i+1)

for i in range(10000) :
    selfNum = d(i+1)
    if selfNum in num :
        num.remove(selfNum)

for i in num :
    print(i)