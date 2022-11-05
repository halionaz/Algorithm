# 설탕 배달
# 그리디 알고리즘 & 수학

N = int(input())

if N % 5 == 0 :
    print(N//5)
else :
    answer = False
    for i in range(N//3+1):
        if (N-i*3)%5 == 0 :
            print((N-i*3)//5 + i)
            answer = True
            break
    if not answer :
        print(-1)