# 트리 순회
# 트리

# 이진 트리 구현은 class로 해도 되지만 단순하게 dictionary로 구현

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