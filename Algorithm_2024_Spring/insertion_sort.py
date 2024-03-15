def InsertionSort(A):
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i+1] = A[i]
            i -= 1
        A[i+1] = key

A=[]
n = int(input())
for i in range(n):
    A.append(int(input()))
 
InsertionSort(A)

for i in A:
    print(i)