import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T) :
    N = int(input())

    haveAns = False
    for i in range(1, max(N,int(N**0.5))) :
        if N % i == 0 :
            if (i + (N//i))%3 == 0 :
                haveAns = True
                print("TAK")
                break
    if not haveAns :
        print("NIE")