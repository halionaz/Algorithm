# 최소 힙
# 우선순위 큐

# 미친 하승준
# 힙을 직접 구현하다

import sys
input = sys.stdin.readline
N = int(input())

heap = [0] # 트리로 만들기에 인덱스를 1부터 시작시킴

for _ in range(N) :
    inp = int(input())
    if inp == 0 :
        # 가장 작은 값을 출력하고, 그 값을 배열에서 제거하는 연산
        if len(heap) == 1:
            print(0)
        else :
            print(heap[1])
            if len(heap) == 2:
                heap.pop()
            else :
                heap[1] = heap.pop()
                key = 1
                while key*2 <= len(heap) - 1 :
                    if key*2 + 1 == len(heap) :
                        if heap[key*2] < heap[key] :
                            heap[key],heap[key*2] = heap[key*2], heap[key]
                            key *= 2
                        else :
                            break
                    else :
                        if heap[key*2] <= heap[key*2+1] :
                            son = key*2
                        else :
                            son = key*2+1
                        if heap[son] < heap[key] :
                            heap[son] , heap[key] = heap[key], heap[son]
                            key = son
                        else :
                            break
    else :
        heap.append(inp)
        key = len(heap) - 1
        while key > 1 :
            if heap[key//2] > heap[key] :
                heap[key//2], heap[key] = heap[key], heap[key//2]
                key //= 2
            else :
                break