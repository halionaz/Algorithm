// 대소문자 바꾸기
// 문자열

#include <iostream>
#include <string>
#include <ctype.h>

int main()
{
   std::string s;
   std::cin >> s;
   for(int i = 0; i < s.length(); i++){
      char c = s[i];
      if(isupper(c)){
         c = tolower(c);
      } else if(islower(c)){
         c = toupper(c);
      }
      std::cout << c;
   }
   std::cout << '\n';

   return 0;
}