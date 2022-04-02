# 회의실 배정
# 그리디 알고리즘

# 가장 대표적인 greedy 문제,
# 끝나는 시간이 빠른 순서대로 채워넣으면 최대 회의 배정 가능

N = int(input())
arr = []
for i in range(N) :
    arr.append(list(map(int,input().split())))
# 끝나는 시간 기준으로 정렬, 끝나는 시간이 같다면 시작하는 시간으로 정렬
arr.sort(key = lambda x: (x[1], x[0]))
end ,ans = 0, 0
for s,e in arr :
    if s >= end :
        ans += 1
        end = e
print(ans)