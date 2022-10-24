//DONE :*)
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main();
int x=0;
int cv,ccv;
int hv,chv;
int human(int chv,int x)
{
    cout<<"What would you add ? ";
    cin>>chv;
    if((chv>=1&&chv<=3)&&(x+chv<=21))
        return chv;
    else
    {
        cout<<"Woah, that number can't be added, dont worry you can try again"<<endl<<endl;
        human(chv,x);
    }
}
int cpumod(int ccv,int x)
{
    if(x+1==21||x+1==13||x+1==17)
        return 1;
    else if(x+2==21||x+2==13||x+2==17)
        return 2;
    else if(x+3==21||x+3==13||x+3==17)
        return 3;
    else 
    {
        ccv=rand()%10;
        if((ccv>=1&&ccv<=3))
            return ccv;
        else
            cpumod(ccv,x);
    }    
}
int cpuhard(int ccv,int x)
{
    if(x+1==21||x+1==13||x+1==17||x+1==9||x+1==5)
        return 1;
    else if(x+2==21||x+2==13||x+2==17||x+2==9||x+2==5)
        return 2;
    else if(x+3==21||x+3==13||x+3==17||x+3==9||x+3==5)
        return 3;
    else 
    {
        ccv=rand()%10;
        if(ccv<=3&&ccv>=1)
            return ccv;
        else
            cpuhard(ccv,x);
    }
}
int cpueasy(int ccv, int x)
{
    if(x+1==21)
        return 1;
    else if(x+2==21)
        return 2;
    else if(x+3==21)
        return 3;
    else 
    {
        ccv=rand()%10;
        if(ccv>=1&&ccv<=3)
            return ccv;
        else
            cpueasy(ccv,x);
    }
}
void checkhum(int x)
{
    if(x==21)
    {
        cout<<endl<<"Wow, you've shown the bot who is the master, YOU WON."<<endl;
        cout<<"CPU SAYS :- I don't belive it, this is luck, try me again"<<endl;
        usleep(1000000);
        string choice;
        cout<<"Do you want to play again ? ";
        cin>>choice;
        if(choice=="yes"||choice=="YES"||choice=="Yes")
            main();
        else
        {
            cout<<endl<<"Have a good day :)";
            exit(0);
        }
    }
}
void checkcpu(int x)
{
    if(x==21)
    {
        cout<<endl<<"Man, thats hard luck, I belive you can win next time, but YOU LOST."<<endl;
        cout<<"CPU SAYS :- I know humans are incapable of beating me, hahaha"<<endl;
        usleep(1000000);
        string choice;
        cout<<"Do you want to play again ? ";
        cin>>choice;
        if(choice=="yes"||choice=="YES"||choice=="Yes")
            main();
        else
        {
            cout<<endl<<"Have a good day :)";
            exit(0);
        }
    }
}
void start()
{
    cout<<"******************************Welcome to the Pile Up Game******************************"<<endl;
    cout<<"->Its a simple game where you must get to 21 before your opponent"<<endl;
    cout<<"->You start the game with 0"<<endl;
    cout<<"->You can add 1,2 or 3 only in your turn"<<endl;
    cout<<"->Don't mind the cpu trash talking :P"<<endl;
    cout<<"->Good Luck and have Fun :)"<<endl;
    cout<<"***************************************************************************************"<<endl;
}
void trash()
{
    int m;
    m=rand()%10;
    if(m==1)
        cout<<"CPU SAYS :- I'll win and I'm the best."<<endl;
    else if(m==3)
        cout<<"CPU SAYS :- Bruh, give me some time to think and beat you."<<endl;
    else if(m==5)
        cout<<"CPU SAYS :- Haha, bet you dint see this comming."<<endl;
    else if(m==7)
        cout<<"CPU SAYS :- You think you won this? How cute XD"<<endl;
    else if(m==9)
        cout<<"CPU SAYS :- Give up already, don't waste your time."<<endl;
    else
        cout<<"CPU SAYS :- I have better things to do than to beat you -_-"<<endl;
}
void easy(int x,int hv,int chv,int cv,int ccv)
{
    while(x<21)
    {
        cout<<endl;
        cout<<"**********Your turn**********"<<endl;
        hv=human(chv,x);
        x+=hv;
        cout<<"We are at "<<x<<endl;
        usleep(1000000);
        checkhum(x);
        cout<<endl;
        cout<<"**********CPU's turn**********"<<endl;
        trash();
        cout<<"CPU is thinking..."<<endl;
        usleep(3000000);
        cout<<endl;
        cv=cpueasy(ccv,x);
        cout<<"CPU added "<<cv<<endl;
        x+=cv;
        cout<<"We are at "<<x<<endl;
        usleep(1000000);
        checkcpu(x);
        cout<<"***************************************************************************************"<<endl;
    }
}
void mod(int x,int hv,int chv,int cv,int ccv)
{
    while(x<21)
    {
        cout<<endl;
        cout<<"**********Your turn**********"<<endl;
        hv=human(chv,x);
        x+=hv;
        cout<<"We are at "<<x<<endl;
        usleep(1000000);
        checkhum(x);
        cout<<endl;
        cout<<"**********CPU's turn**********"<<endl;
        trash();
        cout<<"CPU is thinking..."<<endl;
        usleep(3000000);
        cout<<endl;
        cv=cpumod(ccv,x);
        cout<<"CPU added "<<cv<<endl;
        x+=cv;
        cout<<"We are at "<<x<<endl;
        usleep(1000000);
        checkcpu(x);
        cout<<"***************************************************************************************"<<endl;
    }
}
void hard(int x,int hv,int chv,int cv,int ccv)
{
    while(x<21)
    {
        cout<<endl;
        cout<<"**********Your turn**********"<<endl;
        hv=human(chv,x);
        x+=hv;
        cout<<"We are at "<<x<<endl;
        usleep(1000000);
        checkhum(x);
        cout<<endl;
        cout<<"**********CPU's turn**********"<<endl;
        trash();
        cout<<"CPU is thinking..."<<endl;
        usleep(3000000);
        cout<<endl;
        cv=cpuhard(ccv,x);
        cout<<"CPU added "<<cv<<endl;
        x+=cv;
        cout<<"We are at "<<x<<endl;
        usleep(1000000);
        checkcpu(x);
        cout<<"***************************************************************************************"<<endl;
    }    
}
void level()
{
    cout<<endl<<"Please wait, while we are loading the game :)"<<endl;
    usleep(5000000);
    int chose;
    cout<<endl<<"******************Chose a level******************"<<endl;
    cout<<"Type '1' for Easy"<<endl;
    cout<<"Type '2' for Moderate"<<endl;
    cout<<"Type '3' for Hard"<<endl;
    cout<<"Which level can you face? ";
    cin>>chose;
    if(chose==1)
        easy(x,hv,chv,cv,ccv);
    else if(chose==2)
        mod(x,hv,chv,cv,ccv);
    else if(chose==3)
        hard(x,hv,chv,cv,ccv);
    else
    {
        cout<<endl<<"Thats an invalid entry, try again please."<<endl;
        level();
    }
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout<<endl;
    cout<<"***************************************************************************************"<<endl;
    start();
    level();
}