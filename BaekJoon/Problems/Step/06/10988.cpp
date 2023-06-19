// 10988. 팰린드롬인지 확인하기
// 2023.06.19

/* Sample input & output data
level

1
*/

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    // Input
    string s;
    std::cin >> s;
    int len = s.size();
    int isPalindrome = 1;

    // Judge
    for (int i = 0; i < len/2; i++)     // robust against if odd or even
    {
        if (s[i] != s[len-i-1])
        {
            isPalindrome = 0;
            break;
        }
    }

    // Output
    std::cout << isPalindrome << endl;

    return 0;
}