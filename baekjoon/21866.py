# 추첨을 통해 커피를 받자
# 구현

arr = list(map(int,input().split()))
score = [100,100,200,200,300,300,400,400,500]
summing = 0
hacker = False
for i in range(9) :
    if arr[i] > score[i] :
        hacker = True
        break
    else :
        summing += arr[i]
if hacker :
    print('hacker')
else :
    if summing >= 100 :
        print('draw')
    else :
        print('none')