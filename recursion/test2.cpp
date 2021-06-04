// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main(){
//     int t, x;
//     cin>>t;
//     while(t--){
//         cin>>x;
//         if(x < 11) {
//             cout<<"NO"<<"\n";
//             continue;
//         }
//         stack<int> m, t;
//         int fg = 0;
//         while(x > 0){
//             int d = x%10;
//             x /= 10;
//             m.push(d);
//             t = m;
//             string s = "";
//             while(!t.empty()){
//                 s += to_string(t.top());
//                 t.pop();
//             }
//             int k = stoi(s);
//             if(k%11 == 0) {
//                 cout<<"YES"<<"\n";
//                 fg = 1;
//                 break;
//             }
//         }
//         if(fg == 0) cout<<"NO"<<"\n";
//     }
// }

#include<bits/stdc++.h>
#define int long long
using namespace std;
bool comp(int a, int b){
    return a > b;
}
signed main(){
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        int m1 = 0, m2 = 0;
        sort(a, a+n, comp);
        k = k*2;
        int i=0;
        while(i < k){
            if(i%2 == 0) m1 += a[i];
            else m2 += a[i];
            i++;
        }
        if((k-1)%2 == 0) {
            if(i < n) m1 += a[i];
        } else {
            if(i < n) m2 += a[i];
        }
        cout<<max(m1, m2)<<"\n";
    }
}