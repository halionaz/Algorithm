# maximum_subarray
# 분할 정복

inf = 987654321
n = int(raw_input())
arr = []

for _ in range(n) :
    arr.append(int(raw_input()))

def find_max_crossing_subarray(low, mid, high) :
    left_sum = -inf
    sum = 0
    for i in range(mid, low - 1, -1) :
        sum += arr[i]
        if sum > left_sum :
            left_sum = sum
            max_left = i

    right_sum = -inf
    sum = 0
    for j in range(mid+1, high+1) :
        sum += arr[j]
        if sum > right_sum :
            right_sum = sum
            max_right = j

    return (max_left, max_right, left_sum + right_sum)


def find_maximum_subarray(low, high) :
    if high == low :
        return (low, high, arr[low])
    
    mid = (low + high)//2

    left = find_maximum_subarray(low, mid)
    right = find_maximum_subarray(mid+1, high)
    cross = find_max_crossing_subarray(low, mid, high)

    max_val = max(left[2], right[2], cross[2])

    if max_val == left[2] :
        return left
    elif max_val == right[2] :
        return right
    else :
        return cross

solution = find_maximum_subarray(0, n-1)

for i in solution :
    print(i)
