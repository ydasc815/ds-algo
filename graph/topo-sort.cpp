#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& topo){
    vis[node] = 1;
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i, adj, vis, topo);
        }
    }
    topo.push(node);
}
int main(){
    vector<int> adj[6];
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(1);
    adj[4].push_back(0);
    adj[5].push_back(0);
    adj[5].push_back(2);
    stack<int> topo;
    vector<int> vis(6);
    for(int i=0; i<6; i++){
        if(!vis[i]){
            dfs(i, adj, vis, topo);
        }
    }
    while(!topo.empty()){
        cout<<topo.top()<<" ";
        topo.pop();
    }
}