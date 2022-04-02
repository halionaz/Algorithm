# N-Queen
# 백트래킹

# 백트래킹 끝판왕... 복습 철저히

N = int(input())
isFull = [None]*N
ans = 0
#유망성 판단
def promising(depth,i) :
    if i in isFull :
        return False
    else :
        for j in range(depth) :
            if depth-j == abs(i-isFull[j]) :
                return False
        return True 

def putQueen(depth) :
    global ans
    if depth == N :
        ans += 1
        print(isFull)
        return
    for i in range(N) :
        if promising(depth,i) :
            isFull[depth] = i
            putQueen(depth+1)
            isFull[depth] = None
putQueen(0)
print(ans)

# 개쌉 야매법
# answer = [0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596]
# print(answer[int(input())])