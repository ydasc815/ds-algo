#include<bits/stdc++.h>
using namespace std;
void dijkstra(int src, vector<pair<int, int>> adj[], vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        auto i = pq.top();
        pq.pop();
        // adjacency list pair(i, j): i => node, j => distance to node
        // priority queue pair(i, j): i => distance to node, j => node
        for(auto it:adj[i.second]) {
            if(i.first + it.second < dist[it.first]) {
                dist[it.first] = i.first + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
    for(int i=1; i<dist.size(); i++){
        cout<<"dist to "<<i<<" from src 1 is "<<dist[i]<<"\n";
    }
}
int main(){
    vector<pair<int, int>> adj[6];
    adj[1].push_back({2, 2});
    adj[1].push_back({4, 1});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 4});
    adj[2].push_back({5, 5});
    adj[3].push_back({4, 3});
    adj[3].push_back({5, 1});
    adj[3].push_back({2, 4});
    adj[4].push_back({1, 1});
    adj[4].push_back({3, 3});
    adj[5].push_back({2, 5});
    adj[5].push_back({3, 1});
    vector<int> dist(6, INT_MAX);
    dijkstra(1, adj, dist);
}