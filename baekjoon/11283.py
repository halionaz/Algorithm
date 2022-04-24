# 한글 2
# 구현

# 한글 글자를 사전 순으로 나열했을 때, 몇번째 글자인지를 출력하면 되므로
# utf-8 유니코드 번호를 이용
# '가' : 44032 (시작)
# '힣' : 55203 (끝)

import sys
input = sys.stdin.readline
print(ord(input().rstrip())-44031)