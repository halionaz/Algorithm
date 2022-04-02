# 더하기 사이클
# 수학

N = int(input())

num = (N%10)*10 + (N%10+N//10)%10
cycle = 1
while num != N :
    cycle+=1
    num = (num%10)*10 + (num%10+num//10)%10

print(cycle)