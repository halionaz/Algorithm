# 트리의 순회 
# 트리 & 재귀 & 분할 정복

# postorder에서 각 부분의 마지막 인자는 root
# inorder에서 root를 중심으로 왼쪽과 오른쪽 트리가 나뉨

import sys
sys.setrecursionlimit(10**6)
n = int(input())
inorder = list(map(int,input().split()))
postorder = list(map(int,input().split()))
index = [0]*(n+1)
for i in range(n) :
    index[inorder[i]] = i
# 일일이 인덱스를 찾으려니 시간초과가 뜬다
def preorder(inS,inE,poS,poE) :
    if inS>inE or poS>poE : 
        return
    root = postorder[poE]
    ind = index[root]
    leftSize = ind-inS
    print(root,end=' ')
    preorder(inS,ind-1,poS,poS+leftSize-1)
    preorder(ind+1,inE,poS+leftSize,poE-1)
preorder(0,n-1,0,n-1)
print()