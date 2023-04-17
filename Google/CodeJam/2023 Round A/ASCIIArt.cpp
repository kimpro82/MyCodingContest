/* Sample Input & Output
2
5
31

Case #1: E
Case #2: C
*/


#include <iostream>
#include <vector>
#include <set>
#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    // Run faster
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        // Input N
        ll N;
        cin >> N;

        #ifdef test
            cout << "\n<test>" << endl;
        #endif

        // Find i
        ll i = 1, cum = 26;
        while (cum < N)
        {
            cum += (++i) * 26;
        }

        // Get answer
        ll mod = ((i - 1) * i / 2) * 26;
        char ans = ('A') + (N - 1 - mod) / i;
        #ifdef test
            cout << N << " / " << cum << ' ' << i << ' '  << mod << " / " << N - mod << ' ' << N - 1 - mod << ' ' << (N - 1 - mod) / i << endl;
        #endif

        // Output
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}