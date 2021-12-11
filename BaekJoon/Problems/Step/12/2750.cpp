// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 2750. 수 정렬하기

/* Sample input & output data
5
5
2
3
4
1

1
2
3
4
5
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
    // Input N
    int N;
    cin >> N;

    // Input a vector
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // Sort (default : ascending order)
    sort(v.begin(), v.end());

    // Output (not in a row)
    for (int i = 0; i < N; i++) cout << v[i] << endl;

    return 0;
}