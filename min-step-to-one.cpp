#include<bits/stdc++.h>
using namespace std;
const int inf= (int) 1e9;

int memo[1000];

int reduce(int n){
    if(n==1) return 0;

    int q1, q2, q3= inf;
    if(n%3==0) q1=1+reduce(n/3);
    if(n%2==0) q2=1+reduce(n/2);
    q3=1+reduce(n-1);

    memo[n]=min(q1,min(q2,q3));

    return memo[n];

}

int main(){

    int n;
    cout<<"enter n:"<<endl;
    cin>>n;
    fill(memo, memo+n+1, -1);
    int ans=reduce(n);
    cout<<ans;

    return 0;
}