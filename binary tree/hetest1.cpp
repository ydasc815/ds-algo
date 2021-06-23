// Aditya @ydasc815
#include<bits/stdc++.h>
using namespace std;

bool compute(vector<int>&, int);
void dfs(int, vector<int>&, vector<int>&);
void solve();
bool ans = false;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
}

void solve() {
    int t, n, k; cin>>t;
    while(t--){
        cin>>n>>k;
        ans = false;
        vector<int> v(n, 0);
        for(int i=0; i<n; i++) cin>>v[i];
        cout<<compute(v, k)<<"\n";
    }
}

bool compute(vector<int>& arr, int start) {
    vector<int> vis(arr.size(), 0);
    dfs(start, arr, vis);
    return ans;
}
void dfs(int cur, vector<int>& arr, vector<int>& vis){
    if(cur < 0 || cur >= arr.size() || vis[cur] == 1) return;
    vis[cur] = 1;
    if(arr[cur] == 0) {
        ans = true;
        return;
    }
    dfs(cur + arr[cur], arr, vis);
    dfs(cur - arr[cur], arr, vis);
}