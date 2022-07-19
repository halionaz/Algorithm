# 큰 수 A+B
# 사칙연산 & 임의 정밀도 / 큰 수 연산

# inp = list(map(int,input().split()))
# print(inp[0]+inp[1])

inp = input().split()
A=inp[0]
B=inp[1]
length = 0
if len(A) < len(B) :
    A,B = B,A
c = 0
answer = [None]*len(A)
for i in range(len(A)) :
    if len(B)-i-1>=0 :
        sum = int(A[len(A)-i-1])+int(B[len(B)-i-1])+c
        if sum > 9 :
            c = sum//10
            sum = sum%10
        else :
            c = 0
        answer[len(A)-i-1] = sum
    else : 
        sum = int(A[len(A)-i-1])+c
        if sum > 9 :
            c = sum//10
            sum = sum%10
        else :
            c = 0
        answer[len(A)-i-1] = sum
if c>0 :
    answer.insert(0,c)
print(''.join(str(i) for i in answer))
