#include <bits/stdc++.h>
using namespace std;

int main()
{
    // n is the number of elements in the array
    int n;
    cin>>n; 

    vector <int> v(n);

    // Taking user input
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    // Performing selection sort
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;

        // Iterating to find if there exists a smaller element in the unsorted segment
        for(int j=i+1; j<n; j++)
        {
            if(v[j]<v[min_index])
            {
                min_index = j;
            }
        }

        // If there exists a smaller element then swapping the values
        if(min_index != i)
        {
            swap(v[i],v[min_index]);
        }
    }

    // Output of the sorted array
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
}