# 하노이의 탑 이동 순서
# 재귀

# def hanoi_count(n) :
#     if n == 1:
#         return 1
#     else :
#         return 2*hanoi_count(n-1) + 1
def hanoi(n, fromPos, mid, toPos) :
    # fromPos에 있는 n개의 원판들을 toPos로 옮기는 과정을 출력하는 함수
    if n == 0 :
        return 0
    else :
        hanoi(n-1,fromPos, toPos, mid) # fromPos에 있는 n-1개의 원판은 mid로 옮겨 놓음
        print(fromPos,toPos) # first에 있는 가장 큰 원판을 toPos 위치로
        hanoi(n-1,mid,fromPos,toPos) # mid에 있는 그 윗 원판들을 toPos로
N = int(input())
# print(hanoi_count(N))
print(2**N-1)
hanoi(N,1,2,3)