# 다이얼
# 구현

def strToTime(str) :
    n = ord(str)
    if 65<=n<=67:
        return 3
    elif 68<=n<=70:
        return 4
    elif 71<=n<=73:
        return 5
    elif 74<=n<=76:
        return 6
    elif 77<=n<=79:
        return 7
    elif 80<=n<=83:
        return 8
    elif 84<=n<=86:
        return 9
    elif 87<=n<=90:
        return 10
    else:
        return 11

string = input()
time = 0
for i in string:
    time += strToTime(i)
print(time)