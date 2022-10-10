#include <iostream>
using namespace std;
template <typename T>

class search
{
private:
    T arr[5];
  
public:
    void setdata(T element)
    {
        static int i=0;
        arr[i]=element;
        i++;
    }
    // void setdata(T element);
    int linear(T data)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[j] == data)
                return j;
        }
        return -1;
    }
};

int main()
{
    int choice, ind;
    cout << "1.INTEGER\n2.FLOATING POINT\n3.CHARACTER" << endl;
    cin >> choice;
    if (choice == 1)
    {
        search<int> s1;
        int element, n;
        cout << "Enter the Integer data:";
        for (int j = 0; j < 5; j++)
        {
            cin >> element ;
            s1.setdata(element);
        }
        cout << "Enter the element to search:";
        cin >> n;
        ind=s1.linear(n);
        if(n!=-1)
        {
            cout<<"data found at position "<<ind+1<<endl;
        }
        else
        {
            cout << "data is not found ";
        }
    }
    if (choice == 2)
    {
        search<float> s1;
        float element,n;
        cout << "Enter the floating data:";
        for (int j = 0; j < 5; j++)
        {
            cin >> element ;
            s1.setdata(element);
        }
        cout << "Enter the element to search:";
        cin >> n;
        ind=s1.linear(n);
        if(n!=-1)
        {
            cout<<"data found at position "<<ind+1<<endl;
        }
        else
        {
            cout << "data is not found ";
        }
    }
    if (choice == 3)
    {
        search<char> s1;
        char element,n;
        cout << "Enter the character data:";
        for (int j = 0; j < 5; j++)
        {
            cin >> element ;
            s1.setdata(element);
        }
        cout << "Enter the element to search:";
        cin >> n;
        ind=s1.linear(n);
        if(n!=-1)
        {
            cout<<"data found at position "<<ind+1<<endl;
        }
        else
        {
            cout << "data is not found ";
        }
    }
    return 0;
}
