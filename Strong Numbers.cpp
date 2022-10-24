#include<iostream>
using namespace std;
int Fictorial(const int& num)
{
	int fictorial = 1;
	for (int i = 1; i <= num; i++)
	{
		fictorial = fictorial * i;
	}
	return fictorial;
}
bool Check_Strong_Number(const int& num)
{
	int number = num, sum = 0, remainder;
	while (number != 0)
	{
		remainder = number % 10;
		number = number / 10;
		sum = sum + Fictorial(remainder);
	}
	if (sum == num)
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
	int number;
	cout << "   -------------------------------" << endl;
	cout << "\tCheck Strong Numbers" << endl;
	cout << "   -------------------------------" << endl;
	cout << "Enter a Number: ";
	cin >> number;
	if (Check_Strong_Number(number))
	{
		cout << number << " is Strong number" << endl;
	}
	else
		cout << number << " is not a Strong number" << endl;
}