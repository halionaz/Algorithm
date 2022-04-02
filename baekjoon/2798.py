# 블랙잭
# 브루트포스 알고리즘

# import itertools

# input1 = input().split()
# input2 = input().split()

# CombList = list(itertools.permutations(input2,3))

# minVal = 0
# dirVal = int(input1[1])
# for i in CombList :
#     sum = 0
#     for j in i :
#         sum += int(j)
#     if sum<=dirVal and dirVal-sum < dirVal-minVal :
#         minVal = sum

# print(minVal)

inp = list(map(int,input().split()))
N,M = inp[0],inp[1]
card = list(map(int,input().split()))

min = M
for i in range(N-2) :
    for j in range(i+1,N-1) :
        for l in range(j+1,N) :
            sum = card[i]+card[j]+card[l]
            if sum <= M and M-sum < min :
                min = M-sum
print(M-min)