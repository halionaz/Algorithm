# 파도반 수열
# 다이나믹 프로그래밍 & 수학
# bottom-up

T = int(input())

arr = [0]*101

arr[1],arr[2],arr[3] = 1, 1, 1

for i in range(4,101) :
    arr[i] = arr[i-2] + arr[i-3]

for _ in range(T) :
    print(arr[int(input())])