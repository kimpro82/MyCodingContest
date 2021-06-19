#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int k = 0; k < n; k++)
    {
        cin >> a[k];
    }

    int count = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (a[i-1] != a[j-1])
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}