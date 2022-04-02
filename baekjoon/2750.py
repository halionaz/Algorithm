# 수 정렬하기 
# 정렬

# Python Sort

# N = int(input())
# arr = []
# for i in range(N) :
#     arr.append(int(input()))
# arr.sort()
# for i in arr :
#     print(i)

# Bubble Sort

N = int(input())
arr = []
for i in range(N) :
    arr.append(int(input()))
for i in range(N-1) :
    for j in range(N-1-i) :
        if arr[j]>arr[j+1] :
            arr[j],arr[j+1] = arr[j+1],arr[j]
for i in arr :
    print(i)

# Insertion Sort

# N = int(input())
# arr = []
# for i in range(N) :
#     arr.append(int(input()))
# for i in range(1,N) :
#     for j in range(i) :
#         if arr[i] > arr[i-j-1] :
#             break
#         else : 
#             if i-j-2<0 or arr[i] > arr[i-j-2] :
#                 val = arr[i]
#                 arr.remove(val)
#                 arr.insert(i-j-1,val)
# for i in arr :
#     print(i)