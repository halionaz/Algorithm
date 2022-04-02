# 소트인사이드
# 정렬 & 문자열

# N = input()
# arr = []
# for i in N :
#     arr.append(int(i))
# arr.sort(reverse=True)
# for i in arr :
#     print(i,end='')
# print('')

N = list(input())
for i in range(len(N)-1) :
    for j in range(len(N)-1-i) :
        if int(N[j]) < int(N[j+1]) :
            N[j],N[j+1] = N[j+1],N[j]
print(''.join(N))