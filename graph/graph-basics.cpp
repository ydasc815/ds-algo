#include<bits/stdc++.h>
using namespace std;

vector<int> bfsTrav(int v, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> vis(v+1, 0);

    for(int i=1; i<=v; i++){
        if(!vis[i]) {
            vis[i] = 1;

            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int fr = q.front();
                q.pop();
                bfs.push_back(fr);

                for(int j : adj[fr]) {
                    if(!vis[j]) {
                        vis[j] = 1;
                        bfs.push_back(j);
                    }
                }
            }
        }
    }
    return bfs;
}

int main(){
    // graph input
    // adjacency list
    
}