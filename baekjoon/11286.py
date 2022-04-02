# 절댓값 힙
# 우선순위 큐

# 시잇팔 알고보니 직접 구현하는게 아니었던거임!
# import sys
# input = sys.stdin.readline
# N = int(input())
# heap = [0]
# for _ in range(N) :
#     inp = int(input())
#     if inp == 0:
#         if len(heap) == 1:
#             print(0)
#         else :
#             if len(heap) == 2:
#                 print(heap.pop())
#             else :
#                 print(heap[1])
#                 heap[1] = heap.pop()
#                 key = 1
#                 while key*2 <= len(heap)-1 :
#                     hk = heap[key]
#                     ahk = abs(hk)
#                     if key*2+1 == len(heap) :
#                         hs = heap[key*2]
#                         ahs = abs(hs)
#                         if ahs < ahk or (ahs == ahk and hs < hk):
#                             heap[key*2], heap[key] = heap[key],heap[key*2]
#                             key *= 2
#                         else :
#                             break
#                     else :
#                         hs1,hs2 = heap[key*2], heap[key*2+1]
#                         ahs1, ahs2 = abs(hs1), abs(hs2)
#                         if ahs1 < ahs2 :
#                             son = key*2
#                             hs = hs1
#                             ahs = ahs1
#                         elif ahs1 == ahs2 :
#                             if hs1 <= hs2 :
#                                 son = key*2
#                                 hs = hs1
#                                 ahs = ahs1
#                             else :
#                                 son = key*2+1
#                                 hs = hs2
#                                 ahs = ahs2
#                         else :
#                             son = key*2+1
#                             hs = hs2
#                             ahs = ahs2
#                         if ahs < ahk or (ahs == ahk and hs < hk) :
#                             heap[son], heap[key] = heap[key],heap[son]
#                             key = son
#     else :
#         heap.append(inp)
#         key = len(heap) - 1
#         while key > 1:
#             hk = heap[key]
#             hs = heap[key//2]
#             ahk = abs(hk)
#             ahs = abs(hs)
#             if ahk < ahs or (ahk == ahs and hk < hs):
#                 heap[key],heap[key//2] = heap[key//2],heap[key]
#                 key //= 2
#             else :
#                 break

#heapq 모듈 사용
import sys
import heapq
input = sys.stdin.readline
N = int(input())
heap = []
for _ in range(N) :
    inp = int(input())
    if inp == 0:
        if len(heap) == 0 :
            print(0)
        else :
            print(heapq.heappop(heap)[1])
    else :
        heapq.heappush(heap,(abs(inp),inp))