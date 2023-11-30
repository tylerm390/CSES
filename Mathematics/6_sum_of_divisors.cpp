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
 
const ll mod = 1e9+7, inv2 = 5e8 + 4;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    ll n; cin >> n;
 
    ll res = 0;
 
    ll rt;
    for(rt = 1; rt*rt <= n; rt++)
        res = (res + (n / rt) * rt) % mod;
 
    auto sumi = [&](ll x) -> ll {
        return x * (x+1) % mod * inv2 % mod; 
    };
    
    rt--;
    ll prv = rt;
    for(; rt > 0; rt--) {
        ll nxt = n / rt;
        ll sum = (sumi(nxt % mod) - sumi(prv % mod) + mod) % mod;
        res = (res + rt * sum % mod) % mod;
        prv = nxt;
    }
 
    cout << res << '\n';
 
    return 0;
}