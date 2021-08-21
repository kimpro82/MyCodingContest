// AtCoder Beginner Contest 215
// 2021-08-21(Sat) 21:00 - 22:40, 100 minutes

// C - One More aab aba baa

/* Sample Input & Output
aab 2
aba

baba 4
baab

ydxwacbz 40320
zyxwdcba
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    string S;
    int K;
    cin >> S >> K;

    // Convert string S to vector V
    vector<char> V;
    int sSize = S.size();
    for (int i = 0; i < sSize; i++) V.push_back(S[i]);
    sort(V.begin(), V.end());

    // Get j-th combination of vector V
    for (int j = 1; j < K; j++) next_permutation(V.begin(), V.end());

    // Output
    for (int k = 0; k < sSize; k++) cout << V[k];
    cout << endl;

    return 0;
}