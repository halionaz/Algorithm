# 쉬운 계단 수
# 다이나믹 프로그래밍

# N = int(input())
# arr = [[0]*10,[1]*10]
# arr[1][0] = 0
# for i in range(2,N+1) :
#     arr.append([
#         arr[i-1][1], #0
#         arr[i-1][0] + arr[i-1][2], #1
#         arr[i-1][1] + arr[i-1][3], #2
#         arr[i-1][2] + arr[i-1][4], #3
#         arr[i-1][3] + arr[i-1][5], #4
#         arr[i-1][4] + arr[i-1][6], #5
#         arr[i-1][5] + arr[i-1][7], #6
#         arr[i-1][6] + arr[i-1][8], #7
#         arr[i-1][7] + arr[i-1][9], #8
#         arr[i-1][8] #9
#     ])
# print(sum(arr[N])%1000000000)

#슬라이딩 윈도 기법 - 배열 두개만 잡아놓고 왔다갔다하는 기법

N = int(input())
arr = [[0]*10,[1]*10]
arr[1][0] = 0
for i in range(2,N+1) :
    arr[i%2][0] = arr[(i-1)%2][1]
    arr[i%2][9] = arr[(i-1)%2][8]
    for j in range(1,9) :
        arr[i%2][j] = arr[(i-1)%2][j-1] + arr[(i-1)%2][j+1]
print(sum(arr[N%2])%1000000000)