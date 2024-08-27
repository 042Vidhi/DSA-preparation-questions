// https://leetcode.com/problems/path-with-maximum-probability/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //d
        vector<pair<int,double>>adj[n];
        //make adjacency list
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        //priority queue
        priority_queue<pair<double,int>>pq; //maxheap with max prob
        pq.push({1.0,start_node});//{prob,node}
        vector<double>dist(n,INT_MIN);
        dist[start_node] = 1;

        while(!pq.empty())
        {
            double d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it:adj[node])
            {
                int adjnode = it.first;
                double edw = it.second;
                if(dist[adjnode]<d*edw)
                {
                    dist[adjnode] = d*edw;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        if(dist[end_node]==INT_MIN) return 0.0000;
        else return dist[end_node];
    }
};