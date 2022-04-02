# 하노이의 탑 이동 순서
# 재귀

# def hanoi_count(n) :
#     if n == 1:
#         return 1
#     else :
#         return 2*hanoi_count(n-1) + 1
def hanoi(n, first, second, third) :
    if n == 0 :
        return 0
    else :
        hanoi(n-1,first, third, second)
        print(first,third)
        hanoi(n-1,second,first,third)
N = int(input())
# print(hanoi_count(N))
print(2**N-1)
hanoi(N,1,2,3)