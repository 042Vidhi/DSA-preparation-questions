// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of 
// the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only
//  take nodes directly or indirectly connected from Node 0 in consideration.

// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// code:
#include <bits/stdc++.h>
using namespace std;
class Solution
{   public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        queue<int>q;
        vis[0]=1;
        q.push(0);
        vector <int>bfs;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            bfs.push_back(x);
            for(int i=0;i<adj[x].size();i++)
            {
                if(!vis[adj[x][i]])
                {
                    vis[adj[x][i]]=1;
                    q.push(adj[x][i]);
                    
                }
            }
        }
        return bfs;
        // Code here
    }
};

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int V,E;
        cin>>V>>E;
        vector <int> adj[V];
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int> ans=obj.bfsOfGraph(V,adj);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}