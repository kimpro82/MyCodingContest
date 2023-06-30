// 11005. 진법 변환 2
// 2023.06.28

/* Sample input & output data
60466175 36

ZZZZZ
*/


#include <iostream>
#include <vector>

// #define test
#define endl '\n'

using namespace std;

int main()
{
    // Input : N <= 10^9, 2 <= B <= 36
    int N, B;
    cin >> N >> B;

    // Operate
    vector<char> v;
    int temp;
    char c;
    while (N > 0)
    {
        temp = N % B;                                       // temp must be less than B
        if (temp < 10) c = char(temp + '0');
        else c = char(temp - 10 + 'A');
        v.push_back(c);
        N /= B;

        #ifdef test
            printf("N:%d temp:%d char:%c\n", N, temp, c);
        #endif
    }

    // Output
    int len = v.size();
    for (int i = 0; i < len; i++) cout << v[len-i-1];
    cout << endl;

    return 0;
}
