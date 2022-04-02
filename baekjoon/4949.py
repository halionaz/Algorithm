# 균형잡힌 세상
# 스택 & 문자열

while True :
    inp = input()
    if inp == '.' :
        break
    else :
        stack = []
        isVal = True
        for i in inp :
            if i == '(' :
                stack.append('(')
            elif i == '[' :
                stack.append('[')
            elif i == ')' :
                if len(stack) != 0 and stack[-1] == '(' :
                    stack.pop()
                else :
                    isVal = False
                    break
            elif i == ']' :
                if len(stack) != 0 and stack[-1] == '[' :
                    stack.pop()
                else :
                    isVal = False
                    break
        if isVal and len(stack) == 0:
            print('yes')
        else :
            print('no')