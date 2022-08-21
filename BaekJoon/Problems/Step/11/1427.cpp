// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 1427. 소트인사이드

/* Sample input & output data
2143

4321
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
    // Input N
    string N;
    cin >> N;
    int len = N.size();

    // Input a vector
    vector<int> v;
    for (int i = 0; i < len; i++) v.push_back(N[i] - '0');

    // Sort (default : descending order)
    sort(v.rbegin(), v.rend());                             // need to practice more various ways to use sort()

    // Output (in a row)
    for (int i = 0; i < len; i++) cout << v[i];
    cout << endl;

    return 0;
}