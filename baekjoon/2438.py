# 별 찍기 - 1
# 구현

N = int(input())

for i in range(N) :
    string = ''
    for j in range(i+1) :
        string += '*'
    print(string)