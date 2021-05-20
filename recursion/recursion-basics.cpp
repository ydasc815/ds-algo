#include<bits/stdc++.h>
using namespace std;
int print(int n) {
    if(n == 1) {
        cout<<1<<" ";
        return 1;
    }
    print(n-1);
    cout<<n<<" ";
    return 0;
}
int main() {
    print(100);
}