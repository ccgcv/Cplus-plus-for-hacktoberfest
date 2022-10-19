#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int factorial(int x)
{
    int f=1;
    for (int i = 2; i<= x; i++)
    {
        f=f*i;
    }
    return f;
    
}
int perm (int a,int b)
{
    int permutation,sub;
    sub=a-b;
    permutation=factorial(a)/factorial(sub);
    return permutation;

}
int main()
{
    int n,r;
    cout<<"Enter the numbers you want permutation of"<<endl;
    cin>>n>>r;
    cout<<perm(n,r);
return 0;
}
