# 프린터 큐
# 큐

# from collections import deque
# T = int(input())
# for _ in range(T) :
#     N,M = map(int, input().split())
#     q = deque(map(int,input().split()))
#     count = 0
#     while True :
#         if q[0] == max(q) :
#             if M == 0 :
#                 print(count+1)
#                 break
#             q.popleft()
#             count += 1
#             M -= 1
#         else :
#             if M == 0 :
#                 M = len(q)
#             q.append(q.popleft())
#             M -= 1

T = int(input())
for _ in range(T) :
    N,M = map(int, input().split())
    q = list(map(int,input().split()))
    count = 0
    while True :
        if q[0] == max(q) :
            count += 1
            if M == 0 :
                print(count)
                break
            else :
                q.pop(0)
                M -= 1
        else :
            if M == 0 :
                M = len(q)
            q.append(q.pop(0))
            M -= 1