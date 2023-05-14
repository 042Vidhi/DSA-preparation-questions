// You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th 
// vertex from left to right according to the graph.

// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    
  private:
    void dfs(int node,vector<int> adj[],int vis[],vector<int> &ans)
    {
        vis[node]=1;
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            if(!vis[adj[node][i]])
            dfs(adj[node][i],adj,vis,ans);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        vector<int> ans;
        int i=0;
        dfs(i,adj,vis,ans);
        return ans;
        
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0;i < E;++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}

