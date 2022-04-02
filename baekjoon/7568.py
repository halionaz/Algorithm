# 덩치
# 브루트포스 알고리즘

# manNum = int(input())
# manList = []
# for i in range(manNum) :
#     manList.append(input().split())
#     manList[i][0] = int(manList[i][0])
#     manList[i][1] = int(manList[i][1])

# # manList = [[55, 185], [58, 183], [88, 186], [60, 175], [46, 155]]
# # manNum = 5

# answer = ""
# for i in range(manNum) :
#     score = 1
#     for j in range(manNum) :
#         if manList[i][0] < manList[j][0] and manList[i][1] < manList[j][1] :
#             score+=1
#     answer += str(score) + " "

# print(answer)

N = int(input())
arr,rank = [],''
for i in range(N) :
    arr.append(list(map(int,input().split())))
for i in range(N) :
    count = 1
    for j in range(N) :
        if arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1] :
            count += 1
    rank += str(count)+' '
print(rank)