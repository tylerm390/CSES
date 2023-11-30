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
 
    int n; cin >> n;
 
    ll prv = 1, res = 0;
    rep(i, 2, n+1) {
        ll nxt = (i-1) * (prv + res) % mod;
        prv = res;
        res = nxt;
    }
    
    cout << res << '\n';
 
    return 0;
}