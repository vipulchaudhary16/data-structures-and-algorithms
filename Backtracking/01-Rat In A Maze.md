# [Rat In A Maze](https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include <bits/stdc++.h> 

bool isSafe(int x, int y, int n, vector<vector<int>> &arr, vector<vector<int>> &visited){
    if((x < n and x >= 0) 
       and (y < n and y >= 0) 
       and visited[x][y] == 0 
       and arr[x][y] == 1) 
        return true;
    return false;
}

void solve(int x, int y, vector <vector<int>> & arr, int n, vector<vector<int>> &visited,vector<string> &ans, string path){
    //Reached at destination
    if(x == n - 1 and y == n - 1){
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    //DLRU 
    //Down -> 1,0 -> 2, 0
    if(isSafe(x+1, y, n, arr, visited))
        solve(x+1, y, arr, n, visited, ans, path + 'D');
    //Left -> 1,1 -> 1, 0
    if(isSafe(x, y-1, n, arr, visited))
        solve(x, y-1, arr, n, visited, ans, path + 'L');
    //Right -> 1,1 -> 1, 2
    if(isSafe(x, y+1, n, arr, visited))
        solve(x, y+1, arr, n, visited, ans, path + 'R');
    //Upper -> 1,1 -> 0,1
    if(isSafe(x-1, y, n, arr, visited))
        solve(x-1, y, arr, n, visited, ans, path + 'U');
    //Backtracking
    visited[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector< vector<int> > visited(n, vector<int> (n, 0));
    string path = "";
    //starting point is blocked
    if(arr[0][0] == 0) return ans;
    solve(0, 0, arr, n, visited, ans, path);
    return ans;
}
```