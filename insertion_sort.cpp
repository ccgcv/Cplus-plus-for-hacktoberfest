// Insertion sort in c++
// Author deenu-1001

#include <iostream>
using namespace std;
void insert_sort(int a[], int n)
{
    int temp, k;
    for (int i = 1; i < n; i++)
    {
        k = i;
        temp = a[k];
        for (int j = i - 1; j >= 0; j--)
        {
            
            if (a[j] > temp)
            {   
                a[k] = a[j];
                k--; 
            }
        }
        a[k] = temp;
    //cout<<"pass "<<i<<"\n";
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insert_sort(a, n);
}
