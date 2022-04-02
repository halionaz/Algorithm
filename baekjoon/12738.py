# 가장 긴 증가하는 부분 수열 3
# 이분 탐색 & 가장 긴 증가하는 부분 수열: o(n log n)

N = int(input())
A = list(map(int,input().split()))
LIS = []
def binarySearch(s,e,key) :
    while True :
        if s > e :
            break
        else :
            mid = (s+e)//2
            if LIS[mid] == key :
                return mid
            elif LIS[mid] > key :
                e = mid-1
            else :
                s = mid+1
    if s == len(LIS) :
        LIS.append(key)
    else :
        LIS[s] = key

for i in A :
    length = len(LIS)
    if length :
        binarySearch(0,length-1,i)
    else :
        LIS.append(i)
print(len(LIS))