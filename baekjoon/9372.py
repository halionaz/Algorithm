# 상근이의 여행
# 최소 스패닝 트리 & 트리

# 최소 신장 트리이지만, 그런 복잡한 알고리즘 필요 없다
# 그냥 어차피 모든 노드가 이어지게 되어있으므로
# 최소 간선 수는 노드 수 - 1임

import sys
from collections import deque
input = sys.stdin.readline
T = int(input())
for _ in range(T) :
    N,M = map(int,input().split())
    line = [[] for _ in range(N+1)]
    for _ in range(M) :
        a,b = map(int,input().split())
        line[a].append(b)
        line[b].append(a)

    print(N-1) # 트리의 간선은 노드 수 - 1
    
