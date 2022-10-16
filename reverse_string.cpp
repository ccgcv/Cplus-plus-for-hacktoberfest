// Given a string, we need to reverse the string word wise

#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char input[]) {
    int end,start=0;   // MAde two vairables for the purpose of tarvelling into the string
    for(int i=0;i<=strlen(input);i++)
    {
        if(input[i]==' ' || input[i]=='\0')   // As soon as a space is encountered, we will update the value of end index and will reverse the word accordingly
        {
            end=i-1;
            while(start<end)
            {
                char temp=input[end];
                input[end]=input[start];
                input[start]=temp;
                start++;
                end--;
            }
            start=i+1;   // The starting index will point towards the next word after the space
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cout<<"Enter the string : ";
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}