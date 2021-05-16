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

#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int, int>> vp;
    vp.push_back(pair<int, int>(2, 0));
    vp.push_back(pair<int, int>(15, 3));
    vp.push_back(pair<int, int>(11, 1));
    vp.push_back(pair<int, int>(11, 2));

    sort(vp.begin(), vp.end());
    for(pair<int, int> p : vp) {
        cout<<p.first<<" ";
    }
}