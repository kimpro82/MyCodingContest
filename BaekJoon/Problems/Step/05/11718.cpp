// 11718. 그대로 출력하기
// 2023.06.18

/* Sample input & output data
Hello
Baekjoon
Online Judge
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    string s;

    while (true)
    {
        getline(std::cin, s);
        if (std::cin.eof() == true) break;
        else std::cout << s << endl;            
    }
    return 0;
}