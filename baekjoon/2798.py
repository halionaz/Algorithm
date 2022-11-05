# 블랙잭
# 브루트포스 알고리즘

inp = list(map(int,input().split()))
N,M = inp[0],inp[1]
card = list(map(int,input().split()))

minimum = M
for i in range(N-2) :
    for j in range(i+1,N-1) :
        for l in range(j+1,N) :
            sum = card[i]+card[j]+card[l]
            if sum <= M and M-sum < minimum :
                minimum = M-sum
print(M-minimum)