// 1735. 분수 합
// 2023.07.09

/* Sample input & output data
2 7
3 5

31 35
*/


#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;


int gcdf(int a, int b)                                      // Trial 3 : Euclidean algorithm
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    // Input
    int a, b, c, d, Max, Min, prod, den;
    cin >> a >> b >> c >> d;
    Max = max(b, d);
    Min = min(b, d);
    prod = b * d;
    den = Max;

    // Operate 1 : Get the common denominator
    while (den < prod)
    {
        if (den % Min == 0) break;
        den += Max;
    }

    // Operate 2 : Get the numerator
    int num = a * (den / b) + c * (den / d);

    // Operate 3 : Convert it as an irreducible fraction
    // int gcd = den;                                       // Trial 1 : maybe not the best efficient way but enough to solve in 1 sec.
    // while (gcd > 1)
    // {
    //     if (num % gcd == 0 && den % gcd == 0) break;
    //     else if (gcd == den) gcd = den / 2;              // Trial 2 : added because of my minimum conscience
    //     else gcd--;
    // }
    int gcd = gcdf(num, den);                               // Trial 3

    // Output
    cout << num / gcd << ' ' << den / gcd << endl;

    return 0;
}
