#include <bits/stdc++.h>
using namespace std;
 
void bubblesort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           swapped = true;
        }
     }
     if (swapped == false)
        break;
   }
}
// to dsiplay an array
void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<< arr[i]<<" ";
}
 
int main()
{
    int ele,d;
    cout<<"Enter number of digits you want to store : ";
    cin>>ele;
    int arr[ele];
    cout<<"Enter digits-\n";
    for (int i=0; i<ele;i++){
        cin>>d;
        arr[i]=d;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    bubblesort(arr, n);
    cout <<"\nSorted array: \n";
    display(arr, n);
    return 0;
}
