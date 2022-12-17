// 상어의 저녁식사
// 이분 매칭


// 각 상어마다 정점을 두개씩 만들어서 매칭시켜주면 됨
// "이미 잡아먹힌 상어는 다른 상어들을 잡아먹을 수 없다."는 단서 조항이 붙어있지만
// 그냥 매칭시켜 놓으면, 그 다음에 순서에 따라 항상 그 매칭을 가능하게 할 수 있기에 신경 쓸 필요 없음

// 단, 능력치가 완전히 같은 두 다른 상어의 경우 서로를 잡아먹는 경우까지 구해버릴 수 있기 때문에
// 두 상어중 우위를 임의로 정해 그런 경우 방지
// 또한 한마리가 최대 두마리 상어를 잡아먹을 수 있기 때문에 
// 11376 열혈강호 2처럼 dfs를 두번 수행

#include <iostream>
#include <string.h>
#include <vector>

struct Shark{
    int size, speed, brain;
};
const int diff = 50;

int N;
std::vector<Shark> sharks;
std::vector<int> line[51];
bool doneMatch[51];
int whoEats[51];

int cmp(Shark A, Shark B){
    int same = 0;

    if(A.size < B.size){
        return 0;
    } else if(A.size == B.size){
        same += 1;
    }

    if(A.speed < B.speed){
        return 0;
    } else if(A.speed == B.speed){
        same += 1;
    }

    if(A.brain < B.brain){
        return 0;
    } else if(A.brain == B.brain){
        same += 1;
    }

    if(same == 3){
        // A와 B의 능력치가 같음
        return 2;
    } else {
        // A가 B보다 능력치가 좋음
        return 1;
    }
}

bool dfs(int predator){

    for(int i = 0; i < line[predator].size(); i++){
        int prey = line[predator][i];
        if(!doneMatch[prey]){
            // 이번 탐색에서 아직 건드리지 않은 노드면
            doneMatch[prey] = true;
            if(whoEats[prey] == -1 || dfs(whoEats[prey])){
                whoEats[prey] = predator;
                return 1;
            }
        }
    }

    return 0;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(whoEats, -1, sizeof(whoEats));

    std::cin >> N;

    for(int i = 0; i < N; i++){
        Shark shark;
        std::cin >> shark.size >> shark.speed >> shark.brain;
        sharks.push_back(shark);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int comp = cmp(sharks[i], sharks[j]);
            if(comp == 1 || (comp == 2 && i < j)){
                // i가 j보다 능력 좋음
                // 또는
                // i와 j가 능력이 같다면
                // 인덱스 빠른 쪽이 우위로
                line[i].push_back(j);
            }
        }
    }

    int match = 0;
    
    for(int i = 0; i < N; i++){

        // 두 번의 dfs
        for(int j = 0; j < 2; j++){
            memset(doneMatch, false, sizeof(doneMatch));
            if(dfs(i)){
                match++;
            }
        }
    }

    std::cout << N - match << '\n';

    return 0;
}