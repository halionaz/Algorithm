# maximum_subarray
# 다이나믹 프로그래밍
# bottom-up

# memo[i][0] :: 0 ~ i 수열의 부분합 중 가장 큰 합
# memo[i][1] :: 그 합을 만들 때 왼쪽 인덱스
# memo[i][2] :: 그 합을 만들 때 오른쪽 인덱스

n = int(raw_input())
arr = []
for _ in range(n) :
    arr.append(int(raw_input()))
memo = [(0, 0, 0)]*len(arr)
ans = (arr[0], 0, 0)
for i in range(n) :
    if i == 0 :
        memo[0] = (arr[0], 0, 0)
    else :
        if memo[i-1][0] < 0 :
            memo[i] = (arr[i], i, i)
        else :
            memo[i] = (memo[i-1][0] + arr[i], memo[i-1][1], i)

        if memo[i][0] > ans[0] :
            ans = memo[i]
print(ans[1])
print(ans[2])
print(ans[0])