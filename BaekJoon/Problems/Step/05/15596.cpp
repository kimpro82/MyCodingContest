#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &a)
{
    int n = a.size();                   // not sizeof(a) : get length of the memory space
    cout << "n   : " << n << endl;      // test

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }

    cout << "ans : " << ans << endl;    // test
    return ans;
}

// test
// int main()
// {
//     vector<int> a = {1, 2, 3, 4, 5};
//     sum(a);

//     return 0;
// }