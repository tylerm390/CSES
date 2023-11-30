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
    string s; cin >> s;
    n -= sz(s);
    int k = 0;
    for(char c: s) {
        k += c == '(' ? 1 : -1;
        if(k < 0) {
            cout << 0 << '\n';
            return 0;
        }
    }
 
    if((n-k) % 2 || k > n) {
        cout << 0 << '\n';
        return 0;
    }
 
    n = (n-k) / 2;
    
    int maxVal = 3e6;
    vector<ll> fact(maxVal+1);
    fact[0] = 1;
    rep(i, 1, maxVal+1)
        fact[i] = (fact[i-1] * i) % mod;
 
    vector<ll> invfact(maxVal+1);
    invfact[maxVal] = modpow(fact[maxVal], mod-2);
    for(int i = maxVal-1; i >= 0; i--)
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
    
    ll choose = fact[2*n+k] * invfact[n] % mod * invfact[n+k] % mod;
    ll num = k + 1;
    ll den = n + k + 1;
 
    ll res = choose * num % mod * modpow(den, mod-2) % mod;
 
    cout << res << '\n';
 
    return 0;
}