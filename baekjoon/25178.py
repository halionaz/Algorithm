# 두라무리 휴지
# 구현 & 문자열

def isConsonant(x) :
    # 자음인지 판별해주는 함수
    if x in ['a', 'e', 'i', 'o', 'u'] :
        return False
    else :
        return True

N = int(input())
A = input()
B = input()
if(A[0] == B[0] and A[N-1] == B[N-1] and "".join(filter(isConsonant, A)) == "".join(filter(isConsonant, B))) :
    # A와 B의 첫 글자와 마지막 글자가 똑같고
    # 모음을 뺀 글자가 같을 때
    if(sorted(A) == sorted(B)) :
        # 모음 요소까지 똑같다면
        print("YES")
    else :
        print("NO")
else :
    print("NO")
