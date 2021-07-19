// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 1978. 소수 찾기

/* Sample input & output data
4
1 3 5 7

3
*/


#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    // Input data
    int n;          // n <= 100
    cin >> n;
    vector<int> v;  // v_i <= 1000
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    // Determine if each number of v is a prime number
    int count = 0, prime;
    for (int j = 0; j < n; j++)
    {
        if (v[j] == 1) continue;

        prime = 1;
        for (int k = 2; k < v[j]/2 + 1; k++)
        {
            if (v[j] % k  == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime == 1) count++;

        // test
        // cout << j << " " << v[j] << " " << count << endl;
    }

    // Output
    cout << count << endl;

    return 0;
}