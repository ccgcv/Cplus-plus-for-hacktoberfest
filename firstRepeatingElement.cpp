#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //making an array with all the values as -1
     int *idx = new int[1000000];
    std::fill_n(idx, 1000000, -1);

   
    int minIdx=INT32_MAX;
    //now we will traverse the array and check if the value is -1 or not
    for(int i=0;i<n;i++){
        //if the value is -1 then we will update the value
       if(idx[a[i]]==-1)
        idx[a[i]]=i;
        //if the value is not -1 then we will check if the value is less than minIdx
        else
        {
            //if the value is less than minIdx then we will update the value
            if(idx[a[i]]<minIdx){
                minIdx=idx[a[i]];
            }
        }
    }
    cout<<minIdx;
}