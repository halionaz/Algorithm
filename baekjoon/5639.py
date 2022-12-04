# 이진 검색 트리
# 트리 & 재귀

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

elements = []

def postorder(start,end) :
    if start > end : 
        return
    root = elements[start]
    ind = start + 1
    while ind <= end :
        if elements[ind]<root :
            ind+=1
        else :
            break
    postorder(start+1,ind-1)
    postorder(ind,end)
    print(root)

while True :
    try :
        elements.append(int(input()))
    except :
        break
postorder(0,len(elements)-1)