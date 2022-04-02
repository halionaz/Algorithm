# 후위 표기식
# 스택 

inp = input()
result = ''
stack = []
for i in inp :
    if 'A'<=i<='Z' :
        result += i
    else :
        if i == '(' :
            stack.append(i)
        elif i == '*' or i == '/' :
            while len(stack) and (stack[-1] == '*' or stack[-1] == '/') :
                result += stack.pop()
            stack.append(i)
        elif i == '+' or i == '-' :
            while len(stack) and stack[-1] != '(' :
                result += stack.pop()
            stack.append(i)
        else :
            while len(stack) and stack[-1] != '(' :
                result += stack.pop()
            stack.pop()
while len(stack) :
    result += stack.pop()
print(result)