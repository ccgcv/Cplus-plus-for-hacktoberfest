// Selection sort in C++

#include<iostream>
using namespace std;

void input(int a[], int x)
{
    cout<<"Enter array elements: \n";

    for(int i=0; i<x; i++)
        cin>>a[i];
    

    cout<<"Input array: ";

    for(int i=0; i<x; i++)
        cout<<a[i]<<" ";
}



void sort(int a[], int x)
{
    int temp;
    for(int i=0; i<x; i++)
    {
        for(int j=i; j<x; j++)
        {
            if( a[i] >= a[j+1])
            {
                temp=a[i];
                a[i]=a[j+1];
                a[j+1]=temp;

            }
        }

    }

    cout<<"\nSorted array: ";

    for(int i=0; i<x; i++ )
        cout<<a[i]<<" ";
}

int main()
{
    int x;

    cout<<"Enter number of elements: ";
    cin>>x;

    int a[x];
    input(a,x);
    sort(a,x);

    return 0;
}
