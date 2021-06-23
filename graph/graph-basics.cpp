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
                        q.push(j);
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
    // vector<int> v = {1,2,3,4,5,6,7,8};
    // while(v[0] != 4){
    //     v.erase(v.begin());
    // }
    // for(int i:v) cout<<i<<" ";
    // char* code = "JUMPER";
    // cout<<(code[6] == '\o');
    // string s = "abc";
    // for(int i=0; i<8; i++){
    //     next_permutation(s.begin(), s.end());
    //     cout<<s;
    // }
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        vector<int> v;
        int n, x; cin>>n;
        while(n--){
            cin>>x;
            v.push_back(x);
        }
        for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    }
}