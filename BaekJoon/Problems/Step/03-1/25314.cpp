// 25314. 코딩은 체육과목 입니다
// 2023.06.17

/* Sample input & output data
20

long long long long long int
*/


#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    N /= 4;                                                 // always N/4 > 0 and N%4 = 0

    string str = "long";
    for (int n = 0; n < N; n++) std::cout << str << ' ';
    std::cout << "int" << '\n';

    return 0;
}