# 음계
# 구현

# inp = input()
# if inp == '1 2 3 4 5 6 7 8' :
#     print('ascending')
# elif inp == '8 7 6 5 4 3 2 1' :
#     print('descending')
# else :
#     print('mixed')


inp = input().split()
isAscending = True
isDescending = True
for i in range(len(inp)) :
    if i > 0 :
        if inp[i] < inp[i-1] :
            isAscending = False
        elif inp[i] > inp[i-1] :
            isDescending = False

if isAscending :
    print("ascending")
elif isDescending :
    print("descending")
else :
    print("mixed")
