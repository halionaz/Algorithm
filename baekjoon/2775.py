# 부녀회장이 될테야
# 수학

# 재귀함수로 구현
# def getNum(n,k) :
#     if n == 1 :
#         return 1
#     if k == 0 :
#         return n
#     return getNum(n-1,k) + getNum(n,k-1)

# T = int(input())
# for i in range(T) :
#     k = int(input())
#     n = int(input())
#     print(getNum(n,k))

T = int(input())
room = []
for i in range(15) :
    arr = []
    for j in range(14) :
        arr.append(0)
    room.append(arr)

for i in range(len(room)) :
    for j in range(len(room[i])) :
        if i==0 :
            room[i][j] = j+1
        else :
            if j == 0 :
                room[i][j] = 1
            room[i][j] = room[i-1][j] + room[i][j-1]

for i in range(T) :
    k = int(input())
    n = int(input())
    print(room[k][n-1])