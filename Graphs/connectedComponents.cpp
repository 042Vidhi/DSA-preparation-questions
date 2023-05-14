// Problem:
// Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e,
//  i.e. total number of edges in the graph. Calculate the total number of connected components in the graph.
//   A connected component is a set of vertices in a graph that are linked to each other by paths.

// Input Format:
// First line of input line contains two integers n and e. 
// Next e line will contain two integers u and v meaning that node u and node v are connected to
// each other in undirected fashion. 

// Output Format:
// For each input graph print an integer x denoting total number of connected components.

// Constraints:
// All the input values are well with in the integer range.

// Approach:
// Count the no. of dfs performed on the graph.

//https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/


#include <bits/stdc++.h>
using namespace std;
// void dfs(int node,vector<int> adj,int vis[])
// {
// 	vis[node]=1;
// 	for(auto it:adj[node])
// 	{
// 		if(!vis[it])
// 		dfs(it,adj,vis);
// 	}
// }
vector<int>adj[100001];
int vis[100001];
 
void dfs(int n){
 vis[n]=1;
 for(int i=0;i<adj[n].size();i++){
	int child=adj[n][i];
	if(!vis[child])
	dfs(child);
 }
}
int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
