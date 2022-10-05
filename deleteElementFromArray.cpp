#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,x,index,j;
	cout<<"Enter no. of elements in array before deletion : ";
	cin>>n;
	int arr[n];
	cout<<"Enter all elements here : ";
	for (i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the element to delete : ";
	cin>>x;
	for (i=0;i<n;i++){
		if (arr[i]==x){
			index = i;
			for (j=index;j<n-1;j++){
				arr[j]=arr[j+1];
			}
			n--;
			break;
		}
	}
	cout<<"The modified array is : ";
	for (i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
