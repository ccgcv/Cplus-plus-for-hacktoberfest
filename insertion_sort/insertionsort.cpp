
#include<iostream>
using namespace std;

void display(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
    cout << arr[i] << "\t"; 
    cout << "\n"; 
} 

int main() 
{ 
   
    int size;
    cin>>size;
    
    int array[size];
  
    for(int i=0;i<size;i++)
    cin>>array[i];

    cout << "Before Insertion sort: \n";
    display(array, size);

    int i, key, j;  
    for (i = 1; i < size; i++)
    { key = array[i]; j = i - 1; 

        while (j >= 0 && array[j] > key) 
        {  
            array[j + 1] = array[j];  
            j = j - 1; 
        }

        array[j + 1] = key;  
    }
    cout << "After Insertion sort: \n"; 
    display(array, size);
    
    return 0; 
}
