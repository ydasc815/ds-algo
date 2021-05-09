#include<bits/stdc++.h>
using ll = unsigned long long;
using namespace std;
int main() {
    int n, a, b; cin>>n;
    while(n--){
        cin>>a>>b;
        if((a*b - a) % a != 0) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n"<<a*b - a<<" "<<a<<" "<<a*b<<"\n";
    }
}