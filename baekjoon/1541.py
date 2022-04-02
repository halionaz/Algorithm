# 잃어버린 괄호
# 그리디 알고리즘 & 문자열

# +는 다 더해주면 되고 
# -가 괄호를 결정하므로, -를 분기점으로 sum을 나눔

S=input()
sumArr = []
num = 0 # 숫자를 저장하는 변수
sum = 0 # 숫자 간 합을 저장하는 변수
for i in S :
    if i == '-' :
        # -가 나오면 지금까지의 합을 정리하여 배열에 저장
        sum += num
        sumArr.append(sum)
        num = 0
        sum = 0
    elif i == '+' :
        sum += num
        num = 0
    else :
        num *= 10
        num += int(i)
sum += num
sumArr.append(sum)

# 이제 괄호를 결정할 차례

ans = 0
for i in range(len(sumArr)) :
    if i == 0 :
        # 처음에는 -가 붙어나올 수 없음
        ans = sumArr[i]
    else :
        # +로 이어진 애들을 ()로 묶어 마이너스로 만들음
        ans -= sumArr[i]
print(ans)
