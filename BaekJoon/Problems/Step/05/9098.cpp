// 9098. 문자열
// 2023.06.18

/* Sample input & output data
3
ACDKJFOWIEGHE
O
AB

AE
OO
AB
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    // Input
    int t;
    string s;
    std::cin >> t;

    // Output
    for (int i = 0; i < t; i++)
    {
        std::cin >> s;
        std::cout << s[0] << s[s.size()-1] << endl;
    }

    return 0;
}