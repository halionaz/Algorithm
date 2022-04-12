// 소트인사이드
// 정렬 & 문자열

#include <iostream>
#include <string>
#include <algorithm>

int str[11];

struct greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::string S;
	
	std::cin >> S;
	
	for(int i = 0; i < S.length(); i++){
		str[i] = S[i] - '0';
	}
	
	
	std::sort(str, str+S.length(), greater());
	
	for(int i = 0; i < S.length(); i++){
		std::cout << str[i];
	}
	
	std::cout << '\n';
	
	return 0;
}