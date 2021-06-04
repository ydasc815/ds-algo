// // aditya @ydasc815
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t, n; cin>>t;
//     while(t--){
//         cin>>n;
//         int a[n], mn = INT_MAX; map<int, int> m;
//         for(int i=0; i<n; i++) {
//             cin>>a[i];
//             m[a[i]]++;
//             mn = min(mn, a[i]);
//         }
//         if(m.size() == 1) cout<<0<<"\n";
//         else cout<<n - m[mn]<<"\n";
//     }
// } a/c

// aditya @ydasc815
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t, n; cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        int mx = LONG_LONG_MAX, mn_cnt = 0;
        vector<int> v;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i] <= 0) {
                v.push_back(a[i]);
                mn_cnt++;
            } else {
                mx = min(mx, a[i]);
            }
        }
        int fg = 0;
        sort(v.begin(), v.end());
        for(int i=1; i<v.size(); i++){
            if(v[i] - v[i-1] < mx){
                fg = 1;
                break;
            }
        }
        if(n == 1) cout<<1<<"\n";
        else cout<<mn_cnt + (fg == 0)<<"\n";        
    }
}