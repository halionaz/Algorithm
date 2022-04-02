# 크로아티아 알파벳
# 문자열

s = input()
count = 0
i = 0
while i < len(s) :
    if i != len(s)-1 :
        if s[i] == 'c' :
            if s[i+1] == '=' :
                i += 1
            elif s[i+1] == '-' :
                i += 1
        elif s[i] == 'd' :
            if i != len(s)-2 and s[i+1] == 'z' and s[i+2] == '=' :
                i += 2
            elif s[i+1] == '-' :
                i += 1
        elif s[i] == 'l' and s[i+1] == 'j' :
            i += 1
        elif s[i] == 'n' and s[i+1] == 'j' :
            i += 1
        elif s[i] == 's' and s[i+1] == '=' :
            i += 1
        elif s[i] == 'z' and s[i+1] == '=' :
            i += 1
    i += 1
    count += 1
print(count)