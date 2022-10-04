//This game is developed by Muhib Arshad_(muhib7353)
//Librarires

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>

using namespace std;

//global variables
const int row = 4;
const int col = 4;
int main()
{

  //local varaibles
    bool flag = false;
    int count = 0;
    int matrix[row][col];
    int y = time(0);
    srand(y);
    char startgame;

    //Initlizing the grid to 0
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = 0;
        }
    }
    
    //generating the random number at four sides up,down,left and right
    int rando_startCol = rand() % 4;
    int rando_startRow = rand() % 4;
    int rando_startCol2 = rand() % 4;
    int rando_startRow2 = rand() % 4;
    matrix[rando_startRow][rando_startCol] = (rand() % 2) + 1;
    matrix[rando_startRow2][rando_startCol2] = (rand() % 2) + 1;

    //Spaces line
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }

    //When the game start How it look like
    cout << "\t\t\t\t\t To start the game!" << endl;
    cout << endl;
    cout << "\t\t\t\t\t Enter the S:";
    startgame = getch();
    startgame = tolower(startgame);
    //Input validation
    while (startgame != 's')
    {
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\tInvalid key!" << endl;
        cout << endl;
        cout << "\t\t\t\t\tPlease enter the valid Key:";
        startgame = getch();
    }
    startgame = tolower(startgame);

    //Game start here at S input
    if (startgame == 's')
    {
        //To clear the screen cls command to console
        system("cls");

        //Do while can be used firstly play the game 
        do
        {
            //Spaces line
            for (int i = 0; i < 5; i++)
            {
                cout << endl;
            }
            
            //Instructions to the player
            cout << "\t\t\t\t\tEnter W to move upward:" << endl;
            cout << "\t\t\t\t\tEnter S to move downward:" << endl;
            cout << "\t\t\t\t\tEnter A to move left:" << endl;
            cout << "\t\t\t\t\tEnter D to move right:" << endl;
            cout << "\t\t\t\t\tEnter Q to quit the game:" << endl;
            cout << endl;

            //Grid making deployation
            for (int i = 0; i < row; i++)
            {
                cout << "\t\t\t\t ------------------------------------------" << endl;
                cout << "\t\t\t\t ";
                for (int j = 0; j < col; j++)
                {
                    cout << "|    ";
                    cout << matrix[i][j] << "    ";
                }
                cout << " |";
                cout << endl;
            }
            cout << "\t\t\t\t -------------------------------------------" << endl;

            //Local input command variable
            char ch;

            ///space lines
            for (int i = 0; i < 3; i++)
            {
                cout << endl;
            }

            //inPut
            cout << "\t\t\t\t\tEnter the valid key:";
            ch = getch();
            ch = tolower(ch);
            //Input Validation
            while (ch != 'd' && ch != 'a' && ch != 'w' && ch != 's')
            {
                cout << endl;
                cout << endl;
                cout << "\t\t\t\t\tInvalid Input:" << endl;
                cout << "\t\t\t\t\tplease Enter the valid input:";
                ch = getch();
            }
            ch = tolower(ch);

            //Switch cases used to exexuate that command on every input
            switch (ch)
            {
            case 'd':
            {
                //For Left moving of the numbers
                system("cls");
                for (int i = 0; i < col - 1; i++)
                {
                    for (int j = 0; j < row; j++)
                    {
                        if (matrix[j][i] == matrix[j][i + 1])
                        {
                            //Add the numbers if they are same
                            matrix[j][i + 1] += matrix[j][i];

                            //If user win the game 
                            if (matrix[j][i + 1] == 1024)
                            {
                                for (int i = 0; i < 10; i++)
                                {
                                    cout << endl;
                                }

                                // flag become true and game stops
                                flag = true;
                                cout << "\t\t\t\t\tYou Win the game!:" << endl;
                            }
                            matrix[j][i] = 0;

                            //Move the numbers all to the left side
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col - 1; l++)
                                {
                                    if (matrix[k][l + 1] == 0)
                                    {
                                        int temp;
                                        temp = matrix[k][l + 1];
                                        matrix[k][l + 1] = matrix[k][l];
                                        matrix[k][l] = temp;
                                    }
                                }
                            }
                        }
                    }
                }

//generate the random number after the movement of the numbers
                int randomrow;
                int randomcol;
                randomcol = rand() % 4;
                randomrow = rand() % 4;
                if (matrix[randomrow][randomcol] == 0)
                {
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }
                else
                {
                    while (matrix[randomrow][randomcol] != 0)
                    {
                        int x = time(0);
                        srand(x);
                        randomcol = rand() % 4;
                        randomrow = rand() % 4;
                        if (matrix[randomrow][randomcol] == 0)
                        {
                            break;
                        }
                    }
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }

//Check if all the grid is full and random number find no place to sit then game beacme over 
                int gameover = 0;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            gameover++;
                        }
                    }
                }
                if (gameover == 16)
                {
                    flag = true;
                    cout << "Game over" << endl;
                }
                break;
            }

            // For right moving of the numbers
            case 'a':
            {
                system("cls");
                for (int i = col - 1; i > 0; i--)
                {
                    for (int j = 0; j < row; j++)
                    {
                        // Add the numbers if they are same
                        if (matrix[j][i] == matrix[j][i - 1])
                        {
                            matrix[j][i - 1] += matrix[j][i];

                            // If user win the game
                            if (matrix[j][i - 1] == 1024)
                            {
                                for (int i = 0; i < 10; i++)
                                {
                                    cout << endl;
                                }

                                // flag become true and game stops
                                flag = true;
                                cout << "\t\t\t\t\tYou Win the game!:" << endl;
                            }
                            matrix[j][i] = 0;

                            // Move the numbers all to the Right side
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = col - 1; l > 0; l--)
                                {
                                    if (matrix[k][l - 1] == 0)
                                    {
                                        int temp;
                                        temp = matrix[k][l - 1];
                                        matrix[k][l - 1] = matrix[k][l];
                                        matrix[k][l] = temp;
                                    }
                                }
                            }
                        }
                    }
                }

                // generate the random number after the movement of the numbers
                int randomrow;
                int randomcol;
                randomcol = rand() % 4;
                randomrow = rand() % 4;
                if (matrix[randomrow][randomcol] == 0)
                {
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }
                else
                {
                    while (matrix[randomrow][randomcol] != 0)
                    {
                        int x = time(0);
                        srand(x);
                        randomcol = rand() % 4;
                        randomrow = rand() % 4;
                        if (matrix[randomrow][randomcol] == 0)
                        {
                            break;
                        }
                    }
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }

                // Check if all the grid is full and random number find no place to sit then game beacme over
                int gameover = 0;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            gameover++;
                        }
                    }
                }
                if (gameover == 16)
                {
                    flag = true;
                    cout << "Game over" << endl;
                }
                break;
            }

            // For upward moving of the numbers
            case 'w':
            {
                system("cls");
                for (int i = row - 1; i > 0; i--)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] == matrix[i - 1][j])
                        {

                            // Add the numbers if they are same
                            matrix[i - 1][j] += matrix[i][j];
                            if (matrix[i - 1][j] == 1024)
                            {
                                for (int i = 0; i < 10; i++)
                                {
                                    cout << endl;
                                }

                                // flag become true and game stops
                                flag = true;
                                cout << "\t\t\t\t\tYou Win the game!:" << endl;
                            }
                            matrix[i][j] = 0;

                            // Move the numbers all to the upwaed side
                            for (int k = 0; k < col; k++)
                            {
                                for (int l = row - 1; l > 0; l--)
                                {
                                    if (matrix[l - 1][k] == 0)
                                    {
                                        int temp;
                                        temp = matrix[l - 1][k];
                                        matrix[l - 1][k] = matrix[l][k];
                                        matrix[l][k] = temp;
                                    }
                                }
                            }
                        }
                    }
                }

                // generate the random number after the movement of the numbers
                int randomrow;
                int randomcol;
                randomcol = rand() % 4;
                randomrow = rand() % 4;
                if (matrix[randomrow][randomcol] == 0)
                {
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }
                else
                {
                    while (matrix[randomrow][randomcol] != 0)
                    {
                        int x = time(0);
                        srand(x);
                        randomcol = rand() % 4;
                        randomrow = rand() % 4;
                        if (matrix[randomrow][randomcol] == 0)
                        {
                            break;
                        }
                    }
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }

                // Check if all the grid is full and random number find no place to sit then game beacme over
                int gameover = 0;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            gameover++;
                        }
                    }
                }
                if (gameover == 16)
                {
                    flag = true;
                    cout << "Game over" << endl;
                }
                break;
            }

            // For downnward moving of the numbers
            case 's':
            {
                system("cls");
                for (int i = 0; i < row - 1; i++)
                {
                    for (int j = 0; j < col; j++)
                    {

                        // Add the numbers if they are same
                        if (matrix[i][j] == matrix[i + 1][j])
                        {
                            matrix[i + 1][j] += matrix[i][j];
                            if (matrix[i + 1][j] == 1024)
                            {
                                for (int i = 0; i < 10; i++)
                                {
                                    cout << endl;
                                }

                                // flag become true and game stops
                                flag = true;
                                cout << "\t\t\t\t\tYou Win the game!:" << endl;
                            }
                            matrix[i][j] = 0;

                            // Move the numbers all to the downward side
                            for (int k = 0; k < col; k++)
                            {
                                for (int l = 0; l < row - 1; l++)
                                {
                                    if (matrix[l + 1][k] == 0)
                                    {
                                        int temp;
                                        temp = matrix[l + 1][k];
                                        matrix[l + 1][k] = matrix[l][k];
                                        matrix[l][k] = temp;
                                    }
                                }
                            }
                        }
                    }
                }

                // generate the random number after the movement of the numbers
                int randomrow;
                int randomcol;
                randomcol = rand() % 4;
                randomrow = rand() % 4;
                if (matrix[randomrow][randomcol] == 0)
                {
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }
                else
                {
                    while (matrix[randomrow][randomcol] != 0)
                    {
                        int x = time(0);
                        srand(x);
                        randomcol = rand() % 4;
                        randomrow = rand() % 4;
                        if (matrix[randomrow][randomcol] == 0)
                        {
                            break;
                        }
                    }
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }

                // Check if all the grid is full and random number find no place to sit then game beacme over
                int gameover = 0;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            gameover++;
                        }
                    }
                }
                if (gameover == 16)
                {
                    flag = true;
                    cout << "Game over" << endl;
                }
                break;
            }
            }

        } while (flag == false);//If falg is false continue it to again 
    }

    return 0;
}