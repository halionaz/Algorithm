# 서로 다른 부분 문자열의 개수
# 자료 구조 & 문자열

# 집합과 맵 사용

S = input()
ans = set([])
for i in range(len(S)) :
    for j in range(i, len(S)) :
        ans.add(S[i:j+1])
        
print(len(ans))