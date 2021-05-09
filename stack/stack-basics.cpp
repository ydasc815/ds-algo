#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int fib(int n) {
        if(n == 0 || n == 1) v.push_back(1);
        else v.push_back(n + fib(n-1));
    }
int main() {
    cout<<fib(2);
}