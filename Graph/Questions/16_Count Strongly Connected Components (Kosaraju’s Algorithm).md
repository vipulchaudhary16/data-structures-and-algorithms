### [Count Strongly Connected Components (Kosaraju’s Algorithm)](https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include<bits/stdc++.h>

void dfs(int node, stack<int> &st, unordered_map<int, bool> &visited, 
unordered_map<int, list<int>> &adjList){
	visited[node] = true;
	for(auto nbr : adjList[node]){
		if(!visited[nbr]) dfs(nbr, st, visited, adjList);
	}
	st.push(node);
}

void dfs2(int node, unordered_map<int, bool> &visited, 
unordered_map<int, list<int>> &adjList){
	visited[node] = true;
	for(auto nbr : adjList[node]){
		if(!visited[nbr]) dfs2(nbr, visited, adjList);
	}
}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adjList;
	for(auto e : edges){
		adjList[e[0]].push_back(e[1]);
	}

	//topological sort
	unordered_map<int, bool> visited;
	stack<int> st;

	for(int i = 0; i < v; i++){
		if(!visited[i]) dfs(i, st, visited, adjList);
	}

	//transposing the graph
	unordered_map<int, list<int>> transG;
	for(int i = 0; i < v; i++){
		visited[i] = false;
		for(auto adj : adjList[i]) transG[adj].push_back(i);
	}

	int ans = 0;
	while(!st.empty()){
		int top = st.top(); st.pop();
		if(!visited[top]){
			dfs2(top, visited, transG);
			ans++;
		}
	}

	return ans;
}
```