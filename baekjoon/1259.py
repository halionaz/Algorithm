# 팰린드롬수
# 문자열

while True :
    inp = input()
    if inp == '0' :
        break
    else :
        length = len(inp)
        isTrue = True
        for i in range(length//2) :
            if inp[i] != inp[length-i-1] :
                print('no')
                isTrue= False
                break
        if isTrue :
            print('yes')