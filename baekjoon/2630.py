# 색종이 만들기
# 분할 정복 & 재귀

N = int(input())
arr = []
for _ in range(N) :
    arr.append(list(map(int,input().split())))
blue = 0
white = 0
def divide(divArr) :
    # 색종이 arr가 주어졌을 때, 이 색종이를 색이 섞이지 않도록 나누는 함수
    global blue, white
    isDone = True
    kind = divArr[0][0]

    # 같은 색으로 이루어진 종이인지 판별
    for i in divArr :
        for j in i :
            if kind != j :
                isDone = False
                break
        if not isDone :
            break
    if not isDone :
        # 같은 색으로만 이루어진게 아니라면
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