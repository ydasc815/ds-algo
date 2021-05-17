// #include<bits/stdc++.h>
// #define int unsigned long long
// using namespace std;
// signed main() {
//     int n, a, b; cin>>n;
//     while(n--){
//         cin>>a>>b;
//         if(b == 1) cout<<"NO"<<"\n";
//         else {
//             cout<<"YES"<<"\n";
//             cout<<a<<" "<<a*b<<" "<<a+(a*b)<<"\n";
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int t, n, k; cin>>t;
//     while(t--) {
//         cin>>n>>k;
//         int a[n] = {0};
//         for(int i=0; i<n; i++) cin>>a[i];
//         int i = 0;
//         while(k--){
//             while(a[i] == 0 && i < n) i++;
//             if(i == n) break;
//             a[i]--, a[n-1]++;
//         }
//         for(int i : a) cout<<i<<" ";
//         cout<<"\n";
//     }
// }

#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main() {
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        int a[n];
        map<int, int> m;
        for(int i=0; i<n; i++){
            cin>>a[i];
            m[a[i]]++;
        }
        int fg = 0, fg1 = 0;
        if(m[0] >= 1) {
            for(auto& i : m) {
                if(i.second > 1 && i.first != 0) {
                    fg = 1;
                    break;
                }
            }
        }
        if(n == 2 && a[0] == a[1]) fg = 1;
        if(fg == 0 && fg1 == 0) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
}