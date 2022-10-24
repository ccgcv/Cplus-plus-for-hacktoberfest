#include<iostream>
#include<cmath>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int binary_search(int array[],int size, int key)
{
int start = 0;
int end=size;
    while (start<=end)
    {
       int mid=(start+end)/2;
       if (array[mid]==key)
       {
           return mid+1;
       }
       else if (array[mid]>key)
       {
           end= mid-1;
       }
       else
       {
           start=mid+1;
       }
    }
   return -1; 
}
int main()
{
int n;
int key_main;

cout<<"Enter the size of the array"<<endl;
cin>>n;
int array[n];

for (int i = 0; i < n; i++)
{
    cin>>array[i];

}
cout<<"Enter the number you want position of"<<endl;
cin>>key_main;

cout<<"Your no is at "<<binary_search(array,n,key_main)<<" position";
return 0;
}
