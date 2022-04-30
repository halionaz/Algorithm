// 재귀함수가 뭔가요?
// 재귀

#include <iostream>
#include <string>

int N;
std::string arr[5] = {"\"재귀함수가 뭔가요?\"\n",
                      "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n",
                      "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n",
                      "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n",
                      "라고 답변하였지.\n"
                      };

std::string ending[3] = {
    "____\"재귀함수가 뭔가요?\"\n",
    "____\"재귀함수는 자기 자신을 호출하는 함수라네\"\n",
    "____라고 답변하였지.\n"
};

void func(int depth){

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < depth; j++){
            std::cout << "____";
        }
        std::cout << arr[i];
        if(i == 3){
            if(depth == N-1){

                for(int k = 0; k < 3; k++){
                    for(int j = 0; j < depth; j++){
                        std::cout << "____";
                    }

                    std::cout << ending[k];
                }
                
            } else {
                func(depth+1);
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    std::cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

    func(0);

    return 0;
}