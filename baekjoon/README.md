# ⚖️ Baekjoon Online Judge

## 📌 규칙 사항

- 모든 문제 풀이 소스코드의 제목은 `'문제번호'.확장자` 형식
- ex) `1002.py` 또는 `1005.cpp `
- 문제의 시작 형식은 다음과 같음

```cpp
// 문제 이름
// 문제 태그 (한글, BOJ 알고리즘 분류태그, 각 태그는 &로 연결)

// 개인적 깨달음
```

- 그 아래부터 주석에는 블로그 형식의 문제 풀이 감회 또는 키 포인트들 작성
- 어려웠던 부분이 있으면 그 부분을 명확히 밝히고 어떻게 풀었는지 상세 주석 기입

## 🏷️ 문제 태그 목록

- 구현
    - 많은 조건 분기
- 수학
    - 사칙연산
        - 임의 정밀도 / 큰 수 연산
    - 정수론
        - 소수 판정
            - 에라토스테네스의 체
        - 모듈로 곱셈 역원
        - 페르마의 소정리
        - 유클리드 호제법
        - 중국인의 나머지 정리
    - 기하학
        - *ccw 알고리즘* :: 점 3개를 이은 직선의 방향을 알고자 할 때 유용한 기하 알고리즘
        - 볼록 껍질
            - 볼록 다각형 내부의 점 판정
            - *그라함 스캔 알고리즘* :: 기준점을 잡고, 점을 반시계 방향으로 정렬한 후 볼록껍질이 되는지를 판별
        - 선분 교차 판정 :: ccw를 이용하여 쉽게 구할 수 있음
        - 피타고라스 정리
        - 다각형의 넓이
    - 조합론
    - 선형대수학
    - 누적 합
    - 게임 이론
- 자료 구조
    - 스택
    - 큐
    - 덱
    - 우선순위 큐
    - 문자열
        - 파싱
        - kmp :: prefix와 suffix를 사용해 문자열 패턴 탐색을 최적화함
            - *환형 kmp* :: kmp 문제 중 순환형 아이디어를 사용한 문제
    - *집합과 맵* :: dictionary로도 불리는 자료구조
        - 해시를 사용한 집합과 맵
        - 트리를 사용한 집합과 맵
- 해싱
- 정렬
    - 스위핑
- 브루트포스 알고리즘
    - 백트래킹
    - 시뮬레이션
- 그리디 알고리즘
- 오프라인 쿼리 :: 쿼리를 주어진 순서대로 처리하지 않고, 유리하게 재배치하여 문제 풀이
- 값 / 좌표 압축
- 다이나믹 프로그래밍
    - *bottom-up* :: 상향식 DP, 작은 문제들부터 풀어나가며 전체 문제의 답을 찾는 DP 방식
    - *top-down* :: 메모제이션, 하향식 DP, 큰 문제를 해결하기 위해 작은 문제들을 호출하는 방식, 일반적으로 재귀 호출 사용
    - 배낭 문제
    - 비트마스킹
        - 비트필드를 이용한 다이나믹 프로그래밍
    - 트리에서의 다이나믹 프로그래밍
- 재귀
    - 이분 탐색
        - 매개 변수 탐색
        - 가장 긴 증가하는 부분 수열: o(n log n)
        - 중간에서 만나기
    - 분할 정복
        - 분할 정복을 이용한 거듭제곱
- 그래프 이론
    - 그래프 탐색
        - 깊이 우선 탐색
            - 외판원 순회 문제
            - 오일러 경로 테크닉 :: 15899 문제 참고
        - 너비 우선 탐색
            - 0-1 너비 우선 탐색
        - 분리 집합
    - 위상 정렬
    - 데이크스트라 :: 우선순위큐(힙)을 이용한 최소 경로 탐색 (음수 간선이 있는 경우 사용 불가)
    - 플로이드-워셜 :: 경유지를 통한 최소 경로
    - 벨만-포드 :: 모든 간선을 노드 수 만큼 탐색 (음수 간선이 있는 경우 유용)
        - *difference_constraints_system* :: 7577 문제 참고
    - 최소 스패닝 트리
        - *크루스칼 알고리즘* :: 그래프의 정점을 가장 적은 비용으로 연결하는 알고리즘, union-find(분리 집합) 사용, 최소 스패닝 트리를 구하기 위해 쓰임
    - 이분 그래프 :: 인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프
    - 단절점과 단절선 :: 그래프를 나누는 기점이 되는 단절점과 단절선을 다루는 문제
    - 최대 유량 :: 네트워크 플로우
        - *포드-풀커슨 메소드* :: 최대 유량을 구하기 위해서 유량의 대칭성을 고려한 경로 탐색을 반복하는 전략
            - *에드몬드-카프 알고리즘* :: 포드-풀커스 메소드을 BFS를 통해 구현한 알고리즘 
        - *정점 분할* :: 정점에도 간선처럼 가중치를 주기 위해서 하나의 정점을 in과 out 두 개의 정점으로 나눠 간선화 하는 테크닉
        - 이분 매칭 :: 최대 매칭 수를 구하는 알고리즘, 즉 간선의 용량이 1인 이분 그래프의 최대 유량 구하기, DFS를 통해 최대 유량보다 효율적으로 풀이할 수 있음
- 트리
    - 세그먼트 트리
        - 다차원 세그먼트 트리
        - *펜윅 트리*
        - *inversion counting* :: 세그먼트 트리를 이용해 선분의 교차점 개수를 구하는 알고리즘
        - 머지 소트 트리 :: 세그 트리의 각 노드에서, 해당 노드의 구간에 있는 원소들을 정렬한 상태로 저장하는 자료구조
    - 트라이
- 희소 배열
    - 최소 공통 조상 :: 트리에서 두 노드의 가장 하위 공통 조상을 찾아나가는 알고리즘
- 강한 연결 요소 :: SCC (Strongly Connected Component)
    - *코사라주 알고리즘* :: SCC를 구하는 선형 탐색 알고리즘, 순방향/역방향 그래프를 사용해 DFS 진행
    - *타잔 알고리즘* :: SCC를 구하는 알고리즘, 순방향 DFS와 스택을 이용해 SCC를 묶어낼 수 있음
    - 2-sat :: p와 q 중 하나만 참이면 된다는 조건은, !p이면 q여야 하고, !q이면 p여야 한다는 뜻이다. 이 개념을 이용해 강한 연결 요소로 풀 수 있음.
- 두 포인터
- 슬라이딩 윈도우
- 순열 사이클 분할
- 애드 혹
- 해 구성하기 :: 답을 증명할 수 있는 실제 예시를 구성하는 풀이 방법
- *inf_input* :: 무한 입력 받기
- *py_output_at_once* :: 파이썬에서 리스트 한번에 일괄 출력하기

## 🧱 다시금!
- [x] `1029.cpp` :: 비트필드를 이용한 다이나믹 프로그래밍 & 비트마스킹
- [x] `1086.py` :: 비트필드를 이용한 다이나믹 프로그래밍
- [x] `1097.cpp` :: KMP & 브루트포스 알고리즘
- [x] `1126.cpp` :: 다이나믹 프로그래밍
- [x] `1217.cpp` :: 강한 연결 요소 & 2-sat
- [x] `2416.cpp` :: 강한 연결 요소 & 2-sat
- [x] `2618.py` :: 다이나믹 프로그래밍
- [x] `3648.py` :: 2-sat & 강한 연결 요소
- [x] `3682.cpp` :: 강한 연결 요소
- [x] `3747.cpp` :: 2-sat & 강한 연결 요소
- [x] `4013.cpp` :: 강한 연결 요소 & 다이나믹 프로그래밍
- [x] `4196.cpp` :: 강한 연결 요소
- [x] `4230.cpp` :: 강한 연결 요소 & 2-sat
- [x] `7626.cpp` :: 스위핑 & 세그먼트 트리 & 값 / 좌표압축
- [x] `9120.cpp` :: kmp (인데 해석하기 귀찮아서 아직 복습 안함)
- [x] `10217.py` :: 데이크스트라 & 다이나믹 프로그래밍
- [x] `10266.cpp` :: kmp (환형 kmp)
- [x] `11097.cpp` :: 강한 연결 요소 & 플로이드-워셜
- [x] `11280.cpp` :: 강한 연결 요소 & 2-sat
- [x] `11281.cpp` :: 강한 연결 요소 & 2-sat
- [x] `11585.cpp` :: kmp (환형 kmp)
- [x] `11658.cpp` :: 세그먼트 트리 & 다차원 세그먼트 트리 & 누적 합 (펜윅 트리)
- [x] `12104.cpp` :: kmp (환형 kmp)
- [x] `12126.cpp` :: 애드 혹 & 그리디 알고리즘 (다이아몬드 I)
- [x] `13511.cpp` :: 최소 공통 조상 (플래티넘 III)
- [x] `16225.cpp` :: 그리디 알고리즘 & 우선순위 큐 (다이아몬드 V)
- [x] `16367.cpp` :: 강한 연결 요소 & 2-sat (플래티넘 II)
- [x] `16915.cpp` :: 강한 연결 요소 & 2-sat (플래티넘 III)
- [x] `20149.py` :: 기하학 & 선분 교차 판정