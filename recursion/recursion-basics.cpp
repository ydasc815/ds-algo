// #include<bits/stdc++.h>
// using namespace std;
// int print(int n) {
//     if(n == 1) {
//         cout<<1<<" ";
//         return 1;
//     }
//     print(n-1);
//     cout<<n<<" ";
//     return 0;
// }
// int main() {
//     print(100);
// }

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    vector<int> v = {1, 3, -3, 5, -6, 4, 7, -9, -10, -11};
    int i=0, j = v.size() - 1;
    while(1) {
        if(v[i] > 0) {
            while(v[j] > 0) {
                j--;
                if(i > j) break;
            }
            if(i < j) swap(v[i], v[j]);
        } else i++;
        if(i > j) break;
    }
    for(int n : v) cout<<n<<" ";
}