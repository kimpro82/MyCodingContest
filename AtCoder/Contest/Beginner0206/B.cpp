/* Sample input & output
12
5

100128
447 
*/

#include <iostream>
 
using namespace std;
 
int main()
{
    int n;      // 1 <= n <= 10^9
    cin >> n;
 
    int x = 0, sum = 0;
    do {
        x++;
        sum += x;
    }
    while (sum < n);
 
    cout << x << endl;
 
    return 0;
}