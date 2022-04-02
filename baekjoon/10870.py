# 피보나치 수 5
# 재귀

# n = int(input())

# def 피보나치(N) : 
#     if N == 0 :
#         return 0
#     elif N == 1 :
#         return 1
#     else :
#         return 피보나치(N-1) + 피보나치(N-2)

# print(피보나치(n))

def 피보나치(n) :
    if n == 0 or n == 1 :
        return n
    else :
        return 피보나치(n-1)+피보나치(n-2)

print(피보나치(int(input())))