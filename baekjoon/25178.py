# 두라무리 휴지
# 구현 & 문자열

def func(x) :
    if x in ['a', 'e', 'i', 'o', 'u'] :
        return False
    else :
        return True

N = int(input())
A = input()
B = input()
if(A[0] == B[0] and A[N-1] == B[N-1] and "".join(filter(func, A)) == "".join(filter(func, B))) :
    if(sorted(A) == sorted(B)) :
        print("YES")
    else :
        print("NO")
else :
    print("NO")
