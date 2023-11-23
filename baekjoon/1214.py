# 쿨한 물건 구매
# 브루트포스 알고리즘

import sys
input = sys.stdin.readline

D, P, Q = map(int, input().split())

P, Q = max(P,Q), min(P,Q);

diff = 2e9

# P를 0개, 1개, 2개 ... D // P, D // P + 1개 낼 때 완전 탐색
# 단, P를 Q개 낸다면, 이는 Q를 P개 내는 것과 같기에
# 그 이후 탐색들은 P를 0개, 1개... 내는 것과 아예 같음
# 따라서 더 이상 탐색 안해도 됨

# D // P + 1 해주는 이유는
# D = 17, P = 9, Q = 7과 같이
# P를 2번 쓰는 것이 P 1번, Q 2번 쓰는 것보다 작은 경우가 있기 때문
# 이거 때문에 if문 분기
for i in range(min(D//P, Q) + 2):
    val = D - P * i
    if val >= 0 :
        diff = min(diff, (Q - val % Q) % Q)
        # 마지막에 Q의 나머지 처리를 하는 이유는
        # (D - P * i) % Q가 0이 되는 경우 (D금액을 온전히 낼 수 있는 경우)
        # diff가 Q가 되는 것을 방지하기 위해서임
    else :
        diff = min(diff, P * i - D)

print(D + diff)