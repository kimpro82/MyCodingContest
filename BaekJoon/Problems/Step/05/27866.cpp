// 27866. 문자와 문자열
// 2023.06.18

/* Sample input & output data
Sprout
3

r
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    // Input
    string s;
    int idx;
    std::cin >> s >> idx;

    // Output
    std::cout << s[idx-1] << endl;

    return 0;
}