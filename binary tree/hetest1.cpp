// Aditya @ydasc815
#include<bits/stdc++.h>
#define int unsigned long long
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
    string filename("in01.txt");
    int num;
    ifstream input_file(filename);
    if(!input_file.is_open()) {
        cerr<<"Can't open file";
        return;
    }
    input_file >> num;
    int t, n, k; t = num;
    ofstream output_file;
    output_file.open("out01.txt");
    while(t--){
        // cin>>n>>k;
        input_file >> num; n = num;
        input_file >> num; k = num;
        ans = false;
        vector<int> v(n, 0);
        for(int i=0; i<n; i++) {
            input_file >> num;
            v[i] = num;
        }
        output_file<<compute(v, k)<<"\n";
        
    }
    output_file.close();
    input_file.close();
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