#include <bits/stdc++.h>

using namespace std;

//Program for Game to Guess a number

//Intro Code to be displayed at the beginning of the game
//Asking the user to start a round
void startgame();
void Ask(){
    char c;
    printf(("Are you ready to begin [Y/N] :"));
    scanf(" %c",&c);

    if (c=='Y' || c=='y')
        startgame();

    else
        Ask();

}

int main(){
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Hi and Welcome to Number Guesser!!!\n");
    printf("In your mind choose any number between 1 and 1000\n");
    printf("When the programme displays a number you have will have three options:\n");
    printf("1.Greater\n2.Smaller\n3.Equal\n");
    printf("Give the correct response and your point will be the number of tries the computer takes to guess your number\n");
    printf("Let's Go Then\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");

    Ask();
} 
   


    

//Game Code using binary search
void startgame(){
    int low = 1 , high =  1000; 
    int mid = low + (high-low)/2; //integer division
    int score = 1;
    while(low<=high){
        mid = low + (high-low)/2;
        printf("Choose %d is :\n1. Greater\n2. Smaller\n3. Equal\n than your number\n",mid);
        int Response;
        cin >> Response;        
        if(Response==1){
            //Given number is greater than chossen number. So we limit search region between low and mid-1
            score +=1;
            high = mid-1;
        } 
        else if(Response==2){
            //Given number is smaller than chossen number. So we limit search region between low+1 and mid
            score += 1;
            low = mid+1;
        } 
        else{
            //Given number is equal to the chossen number. So we end the game and give the score
            printf("Your score is %d\n", score); 
            char b;
            printf("Would you like to :\n1.Play Again\n2.Exit\n");
            cin >> b;
            if(b=='1')
                Ask();
            else
                return;
        }
    }
        


}
    



            










