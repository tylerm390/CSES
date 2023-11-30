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
 
const ll mod = 1e9+7, maxVal = 2e6;
 
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
 
    vector<ll> fact(maxVal+1);
    fact[0] = 1;
    rep(i, 1, maxVal+1)
        fact[i] = (fact[i-1] * i) % mod;
 
    vector<ll> invfact(maxVal+1);
    invfact[maxVal] = modpow(fact[maxVal], mod-2);
    for(int i = maxVal-1; i >= 0; i--)
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
 
    int n, m; cin >> n >> m;
 
    int stars = n + m - 1, bars = n - 1;
 
    ll res = fact[stars] * invfact[bars] % mod * invfact[stars - bars] % mod;
    
    cout << res << '\n';
 
    return 0;
}