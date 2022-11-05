# 부녀회장이 될테야
# 수학 & 구현 & 다이나믹 프로그래밍
# bottom-up

T = int(input())
room = [] # room[i][j] :: i층의 j+1호에 사는 인원 수

# 14층까지 미리 0으로 초기화
for i in range(15) :
    arr = []
    for j in range(14) :
        arr.append(0)
    room.append(arr)

for i in range(15) :
    for j in range(14) :
        if i == 0 :
            # 0층인 경우
            room[i][j] = j+1
        else :
            if j == 0 :
                # 1호에 사는 사람은 항상 1명임
                room[i][j] = 1
            room[i][j] = room[i-1][j] + room[i][j-1]

for i in range(T) :
    k = int(input())
    n = int(input())
    print(room[k][n-1])