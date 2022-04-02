# Fly me to the Alpha Centauri
# 수학

T = int(input())
for i in range(T) :
    inp = list(map(int,input().split()))
    dist = inp[1] - inp[0]
    sum = 0
    for j in range(dist) :
        # 2 * (j+1)
        sum += 2*(j+1)
        if sum > dist :
            if dist-(sum-2*(j+1)) > j+1 :
                print(2*j+2)
            else :
                print(2*j+1)
            break
        elif sum == dist :
            print(2*(j+1))
            break