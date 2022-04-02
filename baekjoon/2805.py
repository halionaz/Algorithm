# 나무 자르기
# 이분 탐색 & 매개 변수 탐색

N, M = map(int,input().split())
tree = list(map(int,input().split()))
def cut(h) :
    cnt = 0
    for i in tree :
        if i>h :
            cnt += i-h
    return cnt >= M
start = 1
end = max(tree)
while start <= end :
    mid = (start + end)//2
    if cut(mid) :
        start = mid + 1
    else :
        end = mid -1
print(end)