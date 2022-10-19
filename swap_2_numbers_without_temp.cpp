#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout<<"Enter first number: ";
    cin>>a;

    cout<<"Enter two numbers: ";
    cin>>b;

    a=a*b;   
    b=a/b;    
    a=a/b; 

    cout<<"The first number becomes"<<a<<endl;
    cout<<"The second number becomes"<<b;
    
    return 0;
}