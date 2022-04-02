# 최댓값
# 구현

max = 0
maxIndex = 1
for i in range(9) :
    inp = int(input())
    if inp > max :
        max = inp
        maxIndex = i+1

print(max)
print(maxIndex)
