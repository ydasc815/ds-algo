// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, m;
//     cin>>n>>m;
    
//     vector<int> adj[n+1];
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u>>v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
// }

// bfs of graph
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> adj[]) {
    int vis[V+1] = {0};
    vector<int> res;

    for(int i=1; i<=V; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int f = q.front();
                q.pop();
                res.push_back(f);

                for(auto x : adj[f]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
        }       
    }
    return res;
}

void dfsRec(int n, vector<int>& vis, vector<int> adj[], vector<int>& res) {
    res.push_back(n);
    vis[n] = 1;
    for(auto i:adj[n]){
        if(!vis[i]){
            dfsRec(i, vis, adj, res);
        }
    }
}

vector<int> dfs(int v, vector<int> adj[]){
    vector<int> res;
    vector<int> vis(v+1, 0);
    for(int i=1; i<=v; i++){
        if(!vis[i]){
            dfsRec(i, vis, adj, res);
        }
    }
    return res;
}

int main(){
    int V = 7;
    vector<int> adj[V+1];
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(7);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(3);
    adj[5].push_back(7);
    adj[6].push_back(4);
    adj[7].push_back(2);
    adj[7].push_back(5);
    // vector<int> trv = bfs(V, adj);
    // for(int i : trv){
    //     cout<<i<<" ";
    // }
    vector<int> trv = dfs(V, adj);
    for(int i : trv){
        cout<<i<<" ";
    }
}