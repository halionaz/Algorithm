# 한수 
# 수학 & 브루트포스 알고리즘

# N = int(input())

# def isHanSu(n) :
#     numStr = str(n)
#     lastMin = 20
#     for i in range(len(numStr)-1) : 
#         min = int(numStr[i]) - int(numStr[i+1])
#         if lastMin != 20 and min != lastMin :
#             return False
#         lastMin = min
#     return True

# count = 0
# for i in range(N) :
#     if isHanSu(i+1) :
#         count += 1

# print(count)

def isHansu(X) :
    listX = list(map(int,str(X)))
    dif = 10
    for i in range(len(listX)-1) :
        if dif != 10 and dif != listX[i+1]-listX[i] :
            return False
        else :
            dif = listX[i+1]-listX[i]
    return True

N = int(input())
count = 0
for i in range(N) :
    if isHansu(i+1) :
        count += 1

print(count)