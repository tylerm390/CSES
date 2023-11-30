#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
 
const ll mod = 1e9+7;
 
ll modpow(ll b, ll p) {
    ll res = 1;
    while(p > 0) {
        if(p & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return res;
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    ll n; cin >> n;
 
    ll res = 0;
 
    // 0 deg
    res = (res + modpow(2, n*n)) % mod;
 
    ll sq = n*n - n % 2;
 
    // 90/270 deg
    res = (res + 2*modpow(2, sq/4 + n % 2)) % mod;
 
    // 180 deg
    res = (res + modpow(2, sq/2 + n % 2)) % mod;
 
    res = (res * modpow(4, mod-2)) % mod;
 
    cout << res << '\n';
 
    return 0;
}