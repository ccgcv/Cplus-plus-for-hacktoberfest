#include <bits/stdc++.h>
using namespace std;

/*This code is to calculate (a^(b^c))%m when a,b,c,m all are large.
This code takes care of *nearly* all cases of binary exponentiation.
Applicable for m<=4*10^18, and a,b,c in all ranges of positive long long int.
The time complexity is O(log(m)^2) +O(m^0.5) where m is like the order of max of a,b.
Hope this helps!*/

/*Defining ll as long long int. :). This helps quite a lot.*/
#define ll long long

/*A function to calculate the euler totient of a number.
If you have no idea about totient function, please read it online*/
ll phi(ll m) {
    ll answer = m;
    for (ll i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            while (m % i == 0)
                m /= i;
            answer -= answer / i;
        }
    }
    if (m > 1)
        answer -= answer / m;
    return answer;
}

/*This is to do binary multiplication; This is done to avoid overflow
For example: consider when 10^14*10^5 is present, then long long will overflow
if we calculate directly and then take mod. So instead this function will take
care of that. */
ll bin_mul(ll a, ll b,ll mod)
{
    // If they could directly be mutliplied then ..
    if (a<=2000000000&&b<=2000000000)
        return (a*b)%mod;
    //if a*b>4*10e18.

    //p stands for product, x is a temp variable that is multiplied by 2 each time and added.
    ll p=0,x=a%mod;
    while(b!=0)
    {
        if (b&1) p=(p+x)%mod;
        b>>=1;
        x=(x*2)%mod;
    }
    return p;
}

/*The function for binary exponentiation. It calculates a^b%mod.*/
ll bin_exp(ll a, ll b ,ll mod)
{
    a%=mod;
    ll c=a,ans=1;
    while(b!=0)
    {
        if (b&1) ans=(bin_mul(ans,c,mod))%mod;
        b>>=1;
        c=(bin_mul(c,c,mod))%mod;
    }
    return ans;
}

int main()
{ 
    long long a,b,c,m;
    cin>>a>>b>>c>>m;
    cout<<bin_exp(a,bin_exp(b,c,phi(m)),m)<<endl;
    return 0;
}