#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); i++)
 
using ll = long long;
 
const ll mod = 1e9 + 7;
 
ll modpow(ll b, ll p) {
    ll ans = 1;
    while(p > 0) {
        if(p & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return ans;
}
 
ll fact(int n) {
    ll ans = 1;
    rep(i, 1, n+1)
        ans = (ans * i) % mod;
    return ans;
}
 
ll choose(int n, int k) {
    return fact(n) * modpow(fact(k), mod - 2) % mod * modpow(fact(n - k), mod - 2) % mod;
}
 
int main() {
    int n; cin >> n;
    if(n % 2) {
        cout << 0;
        return 0;
    }
    n >>= 1;
    cout << choose(2*n, n) * modpow(n+1, mod - 2) % mod;
    return 0;
}