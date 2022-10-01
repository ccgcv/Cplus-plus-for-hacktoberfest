#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
    bool prime[100000 + 1];
    memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= 100000; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= 100000; i += p)
                prime[i] = false;
        }
    }
    prime[1] = false;
    cout << "Enter a number less than 100000\n";
    int in;
    cin >> in;
    if (in > 100000 || in < 1)
        cout << "Invalid Input\n";
    else
    {
        if (prime[in])
            cout << "The number is prime\n";
        else
            cout << "The number is not prime\n";
    }
    return 0;
}