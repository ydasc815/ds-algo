// shortest path in undirected graph with unit weights
#include<bits/stdc++.h>
using namespace std;
void bfs(int n, int src, vector<int>adj[]) {
    vector<int> dist(n);
    for(int i=0; i<n; i++) dist[i] = INT_MAX;
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) {
        int fr = q.front();
        q.pop();
        for(auto i:adj[fr]) {
            if(dist[fr] + 1 < dist[i]) {
                dist[i] = 1 + dist[fr];
                q.push(i);
            }
        }
    }
    for(int i=0; i<n; i++) cout<<dist[i]<<" ";
}

int main() {
    vector<int> adj[9];
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(6);
    adj[3].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(2);
    adj[6].push_back(5);
    adj[6].push_back(7);
    adj[6].push_back(8);
    adj[7].push_back(6);
    adj[7].push_back(8);
    adj[8].push_back(6);
    adj[8].push_back(7);

    bfs(9, 0, adj);
}