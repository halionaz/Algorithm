# 소인수분해
# 소수 판정

# import math
# N = int(input())

# num = N
# ans = []
# for i in range(N) :
#     if num == 1 :
#         break
#     for j in range(num-1) :
#         #j+2
#         if num%(j+2) == 0 :
#             ans.append(j+2)
#             num = num//(j+2)
#             break
# for i in ans :
#     print(i)

import math
N = int(input())
for i in range(int(math.sqrt(N))-1) :
    while N%(i+2) == 0:
        print(i+2)
        N = N//(i+2)
if N!=1 :
    print(N)