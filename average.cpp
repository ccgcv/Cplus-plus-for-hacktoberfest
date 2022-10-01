#include<iostream>
using namespace std;

double getAverage(int arr[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum = sum + arr[i];
	}
	double ans = (sum*1.0/n);
	return ans;
}

int main(){
	int n = 10;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<getAverage(arr,n);
}
