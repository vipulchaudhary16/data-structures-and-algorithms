# [The N - Queens Puzzle](https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include <bits/stdc++.h>

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    //same row
    int x = row, y = col;
    while(y >= 0){
        if(board[x][y] == 1) return false;
        y--;
    }
    //lower diagonal
    x = row, y = col;
    while(x < n and y >= 0){
        if(board[x][y] == 1) return false;
        x++;
        y--;
    }
    //upper diagonal
    x = row, y = col;
    while(x >= 0 and y >= 0){
        if(board[x][y] == 1) return false;
        x--;
        y--;
    }  
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    if(col == n){
        vector<int> temp;
        for(auto v : board){
            for(auto i : v)
                temp.push_back(i);
        }
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(isSafe(i, col, board, n)){
            board[i][col] = 1;
            solve(col + 1, ans, board, n);
            board[i][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n,0));
    solve(0, ans, board, n);
    return ans;
}