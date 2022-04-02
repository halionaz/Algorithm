# DSLR
# 너비 우선 탐색

import sys
from collections import deque
input = sys.stdin.readline
def main() :
    T = int(input())
    for _ in range(T) :
        A,B = map(int,input().split())
        dp = [[-1,-1,-1] for _ in range(10000)]
        dp[A] = [0,-1,-1]
        queue = deque([A])
        while len(queue) :
            x = queue.popleft()
            if x == B :
                break
            if dp[(x*2)%10000][0] == -1 : #D
                dp[(x*2)%10000] = [dp[x][0] + 1,0,x]
                queue.append((x*2)%10000)
            if x>0 and dp[x-1][0] == -1 : #S
                dp[x-1] = [dp[x][0] + 1,1,x]
                queue.append(x-1)
            elif x == 0 and dp[9999][0] == -1 :
                dp[9999] = [dp[x][0] + 1,1,x]
                queue.append(9999)
            lval = (x*10)%10000+x//1000
            rval = (x%10)*1000+(x//10)
            if dp[lval][0] == -1 : #L
                dp[lval] = [dp[x][0] + 1, 2,x]
                queue.append(lval)
            if dp[rval][0] == -1 : #R
                dp[rval] = [dp[x][0] + 1, 3,x]
                queue.append(rval)
        ans = []
        ind = B
        while True :
            if dp[ind][1] == -1 :
                break
            word = ['D','S','L','R']
            ans.append(word[dp[ind][1]])
            ind = dp[ind][2]
        ans.reverse()
        print(''.join(ans))
main()