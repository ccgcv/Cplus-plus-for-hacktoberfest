/*
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

Example 1:

Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
*/

class Solution {
public:
int f(int i1,int j1,int i2,int j2,int rows,vector<vector<int>> &grid,vector<vector<vector<vector<int>>>> &dp){
    if(i1>=rows || i2>=rows || j1>=rows || j2>=rows || grid[i1][j1]==-1 || grid[i2][j2]==-1) return -1e8;
    if(i1==rows-1 && j1==rows-1) return dp[i1][j1][i2][j2]=grid[i1][j1];
    int value;
    if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
    if(i1==i2 && j1==j2) value=grid[i1][j1];
    else value=grid[i1][j1]+grid[i2][j2];
    int a=f(i1+1,j1,i2+1,j2,rows,grid,dp);
    int b=f(i1,j1+1,i2,j2+1,rows,grid,dp);
    int c=f(i1+1,j1,i2,j2+1,rows,grid,dp);
    int d=f(i1,j1+1,i2+1,j2,rows,grid,dp);
    return dp[i1][j1][i2][j2]= value+max(max(a,b),max(c,d));
}
    
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        vector<vector<vector<vector<int>>>> dp(rows,vector<vector<vector<int>>> (rows,vector<vector<int>> (rows,vector<int> (rows,-1))));
       int a= f(0,0,0,0,grid.size(),grid,dp);
        if(a<0) return 0;
        return a;
    }
};

