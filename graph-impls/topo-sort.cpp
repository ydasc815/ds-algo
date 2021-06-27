#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
    vis[node] = 1;
    for(auto i:adj[node]) {
        if(!vis[i]){
            vis[i] = 1;
            dfs(i, adj, vis, st);
        }
    }
    st.push(node); // topo sort accumulates here
}
