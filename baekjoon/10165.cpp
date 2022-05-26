// 버스 노선
// 그리디 알고리즘 & 스위핑

// 그리디한 라인 스위핑으로 풀리는 문제
// 시작점 기준으로 정렬하고, 시작점이 같다면 끝점을 '내림차순'으로 정렬함
// 정렬된 순서대로 끝점을 포인터로 두고
// 포인터보다 그 다음 경로의 끝점이 크다면 포인터를 갱신
// 포인터보다 그 다음 경로의 끝점이 작다면 그 다음 경로는 이전 경로에 무조건 속함
// (시작점은 그 전보다 클텐데 끝은 그보다 작기 때문)

// 다만 경로가 원형이기 때문에 0을 지나는 경로에 대한 예외처리가 필요한 문제

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll N, M, a, b;

struct Bus {
	ll num, a, b;
};

std::vector<Bus> normal, pass0;

bool compare(const Bus& A, const Bus& B) {
	if (A.a != B.a) return A.a < B.a;
	else return A.b > B.b;
}

bool ans[500001];
int main() {

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> N >> M;

	ll pass0minStart = 1e12; // 0을 지나는 루트의 시작점 중 가장 작은 값
    ll pass0maxEnd = -1; // 0을 지나는 루트의 끝점 중 가장 큰 값

	for (int i = 1; i <= M; i++) {

		Bus bus;

        std::cin >> bus.a >> bus.b;

        bus.num = i;
        
		if (bus.a < bus.b) {
            // 0을 거치지 않는 정상적 루트
			normal.push_back(bus);

		} else {
            // 0을 거치는 루트
			pass0minStart = std::min(pass0minStart, bus.a);
			pass0maxEnd = std::max(pass0maxEnd, bus.b);
            // 0을 지나는 애들끼리도 스위핑을 통한 비교가 필요하므로, N을 더하게 하여 일직선화 시킴
			bus.b = bus.b + N;
            
			pass0.push_back(bus);

		}
		ans[i] = true;
	}

    // 스위핑을 위한 정렬,
    // 시작점 기준 오름차순으로, 시작점이 같다면 끝점 기준 내림차순
	std::sort(normal.begin(), normal.end(), compare);
	std::sort(pass0.begin(), pass0.end(), compare);

	int right = 0;
    
    // 0을 지나지 않는 루트들
    for (int i = 0; i < normal.size(); i++) {

        if (pass0minStart <= normal[i].a){
            // 루트의 시작점이 0을 지나가는 버스의 시작보다 크다면 무조건 그 버스루트에 속함
            ans[normal[i].num] = false;
        }
        if (pass0maxEnd >= normal[i].b){
            // 루트의 끝점이 0을 지나온 버스의 끝보다 작다면 무조건 그 버스루트에 속함
            ans[normal[i].num] = false;
        }

        // 라인 스위핑
        if (normal[i].b <= right) {
            ans[normal[i].num] = false;
        } else {
            right = normal[i].b;
        }
    }

	right = 0;
    
    // 0을 지나는 루트들
	for (int i = 0; i < pass0.size(); i++) {
		if (pass0[i].b <= right) {
			ans[pass0[i].num] = false;
		} else {
			right = pass0[i].b;
		}
	}

	for (int i = 1; i <= M; i++) {
		if (ans[i]) {
			std::cout << i << ' ';
		}
	}

    std::cout << '\n';

	return 0;
}