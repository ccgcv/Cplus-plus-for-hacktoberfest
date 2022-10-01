#include <bits/stdc++.h>
using namespace std;

bool isPlace(vector<int>&, int, int);
void nqueen(vector<int>&, int, int, int&);
void prettyPrint(vector<int>&);

int main() {

    cout << "\nThis program finds out positions of N - Queens.\n" << endl;
    int size, queens;
    cout << "Enter the size of chess board : ";
    cin >> size;
    cout << "Enter the number of queens to consider : ";
    cin >> queens;

    vector<int> board(size, 0);
    
    int count = 0;

    nqueen(board, 0, queens, count);
    
    cout<<"\n\nThere are "<<count<<" possible solutions.";

    return 0;
}

void nqueen(vector<int> &board, int current, int queens, int &count) {
    // Here we traverse through all rows of the board
    for (int col = 0; col < board.size(); col += 1) {
        if (isPlace(board, current, col)) {
            // If this column can accept a queen
            // NOTE - The number of the queen represents its row,
            // valuea at that index represents the col it is placed in
            board[current] = col;

            if (current == queens-1) {
                prettyPrint(board);
                count++;
                cout << endl;
            } else nqueen(board, current + 1, queens, count);
        }
    }
}

bool isPlace(vector<int> &board, int current, int col) {
    // Here we traverse through all columns of the given row
    for (int j = 0; j < current; j += 1) {
        // This ensures that not only are there no queens below or above
        // But also queens are absent from diagonals
        if (board[j] == col || abs(board[j] - col) == abs(j - current)) return false;
    }
    return true;
}

void prettyPrint(vector<int> &board) {
    for (int i = 0; i < board.size(); i += 1) {
        cout << endl;
        for (int j = 0; j < board.size(); j += 1) {
            if (board[i] == j) cout << "Q" << " ";
            else cout <<  "* ";
        }
    }
}
