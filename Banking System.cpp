#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

class bank
{
    float balance, rate;

    public:
    
        bank(float cash, float r)
        {
            usleep(1000000);
            balance = cash;
            rate = r;
            cout << "Successfully opened your new account!" << endl;
            usleep(1000000);
            cout<<"\033[2J\033[1;1H";
        }
        
        void deposit()
        {
            usleep(1000000);
            float d;
            cout << "Enter the amount you want to deposit in your account: ";
            cin >> d;
            balance += d;
            cout << "Successfully deposited the amount mentioned!" << endl;
        }
        
        void withdraw()
        {
            usleep(1000000);
            float withdrawal;
            cout << "Enter the amount you want to withdraw from your account: ";
            cin >> withdrawal;
            if (balance - withdrawal < 1000)
                cout << "Not enough cash available to withdraw" << endl;
            else
            {
                balance -= withdrawal;
                cout << "Successfully withdrawn the amount mentioned!" << endl;
            }
        }
        
        float calcinterest(int time)
        {
            usleep(1000000);
            float amount;
            amount = balance * pow((1 + (rate / 100)), time);
            float interest = amount - balance;
            balance = amount;
            return interest;
        }
        
        float getbalance()
        {
            usleep(1000000);
            return balance;
        }
        
        ~bank()
        {
            usleep(1000000);
            cout << "Hence,successfully closed your account!" << endl;
        }
};

class loan
{
    private:
        int temp;
        
    public:
    void approval(float credit_score, float loan_amount)
    {
        usleep(1000000);
        temp=0;
        if(loan_amount<1000)
            cout<<"This loan amount is not available"<<endl;
            
        if(loan_amount>=10000000&&credit_score>=800)
        {
            cout<<"You are eligible for this loan."<<endl;
            temp++;
        }
        
        if(loan_amount>=1000000&&credit_score>=650&&loan_amount<10000000)
        {
            cout<<"You are eligible for this loan."<<endl;
            temp++;
        }
        
        if(loan_amount>=100000&&credit_score>=450&&loan_amount<1000000)
        {
            cout<<"You are eligible for this loan."<<endl;
            temp++;
        }
        
        if(loan_amount>=10000&&credit_score>=300&&loan_amount<100000)
        {
            cout<<"You are eligible for this loan."<<endl;
            temp++;
        }
        
        if(loan_amount>=1000&&credit_score>=200&&loan_amount<10000)
        {
            cout<<"You are eligible for this loan."<<endl;
            temp++;
        }
        
        if(temp==0)
            cout<<"Sorry, this credit score can not fetch this amount of loan."<<endl;
    }
    
    void loan_approval()
    {
        usleep(1000000);
        float credit_score, loan_amount;
        cout<<"Enter your present credit score - ";
        cin>>credit_score;
        cout<<"Enter the amount of loan you want to request - ";
        cin>>loan_amount;
        approval(credit_score,loan_amount);
    }
}loan_class;

int n = 0;
void menu(bank &ob)
{
    cout<<"\033[2J\033[1;1H";
    cout << "\tMENU\n";
    cout << "1.DEPOSIT MONEY\n";
    cout << "2.WITHDRAW MONEY\n";
    cout << "3.CALCULATE INTEREST\n";
    cout << "4.DISPLAY AVAILABLE BALANCE\n";
    cout << "5.CHECK LOAN APPROVAL\n";
    cout << "6.CLOSE ACCOUNT\n";
    int ch;
    cin >> ch;
    cout<<"\033[2J\033[1;1H";
    switch (ch)
    {
        case 1:
            ob.deposit();
            usleep(1000000);
            return;
        case 2:
            ob.withdraw();
            usleep(1000000);
            return;
        case 3:
            int t;
            cout << "Enter the time (in years) till when you want to keep the money in bank account: ";
            cin >> t;
            cout << "The interest you got is: " << ob.calcinterest(t) << endl;
            usleep(1000000);
            return;
        case 4:
            cout << "The current balance is: " << ob.getbalance() << endl;
            usleep(1000000);
            return;
        case 5:
            loan_class.loan_approval();
            usleep(1000000);
            return;
        case 6:
            n = 1;
            usleep(1000000);
            return;
    }
}

// Driver Code
int main()
{
    cout<<"\033[2J\033[1;1H";
    int cash, rate;
    cout << "Let's open the bank account first!\n";
    usleep(1000000);
    cout << "Enter initial balance: ";
    cin >> cash;
    cout << "Enter the rate of interest of the bank: ";
    cin >> rate;
    bank account(cash, rate);
    while (1)
    {
        menu(account);
        if (n == 1)
            break;
    }
    return 0;
}