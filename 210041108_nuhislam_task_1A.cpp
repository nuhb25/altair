#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std ;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int start, int ends)
{
    visited [start]=true ;
    ends++;
    if(ends==adj.size())
        return true;

    for(int i=0;i<adj[start].size();i++)
    {
        if(visited[adj[start][i]] == false)
        {
            if(dfs(adj, visited, adj[start][i], ends))
            {
                return  true;
            }
        }
    }
    return false;

}
bool path(int n,vector<vector<int>>&v)
{
    vector<vector<int>> adj(n);
    for(int i=0;i<v.size();i++)
    {
        adj[v[i][0]].push_back(v[i][1]);
        adj[v[i][1]].push_back(v[i][0]);
    }
    vector<bool> visited(n,false);
    return dfs(adj, visited, 0, 0);
}
int main()
{
    int vert=7;
    vector<vector<int>> v = {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
    //cout<<v.size();
    bool ans = path(vert,v);
    cout<<(ans? "True" : "False")<< endl;
}

