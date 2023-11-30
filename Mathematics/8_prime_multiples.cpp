#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<ll>;
using vii = vector<pii>;
using vvi = vector<vi>;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, k; cin >> n >> k;
    vi a(k);
    for(ll &ai: a) cin >> ai;
 
    ll ans = 0;
 
    rep(mask, 1, (1 << k)) {
        ll prod = 1;
        bool tooBig = false;
        rep(i, 0, k) {
            if((mask & (1 << i)) == 0)
                continue;
            if(prod > (n + a[i] - 1) / a[i]) {
                tooBig = true;
                break;
            }
            prod *= a[i];
        }
 
        if(tooBig) continue;
 
        bool include = __builtin_popcount(mask) % 2;
 
        if(include)
            ans += n / prod;
        else
            ans -= n / prod;
    }
 
    cout << ans << endl;
 
    return 0;
}