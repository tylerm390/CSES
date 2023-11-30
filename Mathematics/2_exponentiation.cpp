#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll mod = 1000000007;
 
ll modpow(ll b, ll p) {
    ll ans = 1;
    while(p > 0) {
        if(p & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return ans;
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    while(n--) {
        int a, b; cin >> a >> b;
        cout << modpow(a, b) << '\n';
    }
    return 0;
}