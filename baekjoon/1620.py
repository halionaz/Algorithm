# 나는야 포켓몬 마스터 이다솜 
# 해시를 사용한 집합과 맵
# 집합과 맵

import sys
input = sys.stdin.readline
N,M = map(int,input().split());
monNum = ['start']
monDict = {}
for i in range(N) :
    monNum.append(input().rstrip())
    monDict[monNum[i+1]] = i+1
for _ in range(M) :
    inp = input().rstrip()
    try :
        print(monNum[int(inp)])
    except :
        print(monDict[inp])