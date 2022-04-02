# 색종이 만들기
# 분할 정복 & 재귀

N = int(input())
arr = []
for _ in range(N) :
    arr.append(list(map(int,input().split())))
blue = 0
white = 0
def divide(divArr) :
    global blue, white
    isDone = True
    kind = divArr[0][0]
    for i in divArr :
        for j in i :
            if kind != j :
                isDone = False
                break
        if not isDone :
            break
    if not isDone :
        length = len(divArr)//2
        divide([divArr[i][:length] for i in range(length)])
        divide([divArr[i][length:] for i in range(length)])
        divide([divArr[i][:length] for i in range(length,length*2)])
        divide([divArr[i][length:] for i in range(length,length*2)])
    else :
        if kind :
            blue += 1
        else :
            white += 1
divide(arr)
print(white)
print(blue)