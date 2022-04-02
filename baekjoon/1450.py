# 냅색문제
# 이분 탐색 & 중간에서 만나기 & 브루트포스 알고리즘

# 1208, 부분수열의 합 2와 유사한 풀이

# 브루트포스로 리스트 반의 모든 가능합 리스트를 구함
def a_brute_force(l, w):
    if l >= len(a_weight):
        a_sum.append(w)
        return
    a_brute_force(l + 1, w)
    a_brute_force(l + 1, w + a_weight[l])

def b_brute_force(l, w):
    if l >= len(b_weight):
        b_sum.append(w)
        return
    b_brute_force(l + 1, w)
    b_brute_force(l + 1, w + b_weight[l])

# 상한선 이분 탐색 알고리즘
def lower_bound(start, end, key):
    while start < end:
        mid = (start + end) // 2

        if b_sum[mid] <= key:
            start = mid + 1
        else:
            end = mid
    return end

N, C = map(int, input().split())
weight = list(map(int, input().split()))
ans = 0
a_weight = weight[:N // 2]
b_weight = weight[N // 2:]
a_sum = []
b_sum = []
a_brute_force(0, 0)
b_brute_force(0, 0)
b_sum.sort()
for i in a_sum:
    # a의 가능합 + b의 가능합이 가능한 경우 탐색
    x = C-i
    if not x < 0:      
        ans += (lower_bound(0, len(b_sum), x))    
print(ans)