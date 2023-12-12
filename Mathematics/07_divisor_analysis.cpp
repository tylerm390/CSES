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
 
    vector<ll> p(n), k(n);
    rep(i, 0, n) cin >> p[i] >> k[i];
 
    ll cnt = 1;
    for(int ki: k)
        cnt = (cnt * (ki+1)) % mod;
    
    ll sum = 1;
    rep(i, 0, n) {
        ll num = (modpow(p[i], k[i] + 1) - 1 + mod) % mod;
        ll den = (p[i] - 1) % mod;
        ll geo = (num * modpow(den, mod - 2)) % mod;
        sum = (sum * geo) % mod;
    }
 
    ll base = 1, power = 1;
    bool halved = false;
    rep(i, 0, n) {
        if(!halved && (k[i] & 1)) {
            power = (power * ((k[i] + 1) / 2)) % (mod - 1);
            halved = true;
        }
        else power = (power * (k[i] + 1)) % (mod - 1);
    }
 
    rep(i, 0, n) {
        if(!halved) k[i] /= 2;
        base = (base * modpow(p[i], k[i])) % mod;
    }
 
    ll prod = modpow(base, power);
 
    cout << cnt << ' ' << sum << ' ' << prod << '\n';
 
    return 0;
}