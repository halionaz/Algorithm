# Hashing
# 해싱

L = int(input())
#Hash Function
S = input()
sum = 0
for i in range(L) :
    sum += (31**i)*(ord(S[i])-96)
print(sum%1234567891)