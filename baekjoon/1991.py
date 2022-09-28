# 트리 순회
# 트리 & 재귀

# 이진 트리 구현은 class로 해도 되지만 단순하게 dictionary로 구현

# 22.09.28
# 이진트리 구현을 class나 dict로 하는 미친놈이 있다?
# 그냥 배열 쓰셈... tree[1]-tree[2] - tree[4] & tree[5]
#                           tree[3] - tree[6] & tree[7] 식으로 tree[n]의 자식은 tree[n*2]와 tree[n*2+1]

import sys
input = sys.stdin.readline
N = int(input())
tree = {}
for _ in range(N) :
    root,l,r = input().rstrip().split()
    tree[root] = (l,r)
def preorder(node) :
    if node == '.' :
        return
    else :
        print(node,end='')
        preorder(tree[node][0])
        preorder(tree[node][1])
def inorder(node) :
    if node == '.' :
        return
    else :
        inorder(tree[node][0])
        print(node,end='')
        inorder(tree[node][1])
def postorder(node) :
    if node == '.' :
        return
    else :
        postorder(tree[node][0])
        postorder(tree[node][1])
        print(node,end='')
preorder('A')
print()
inorder('A')
print()
postorder('A')
print()