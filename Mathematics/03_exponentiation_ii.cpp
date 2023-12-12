#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
 
ll modpow(ll b, ll p, ll mod) {
    ll ans = 1;
    while(p > 0) {
        if(p & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return ans;
}
 
const ll mod = 1e9 + 7;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n; cin >> n;
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << modpow(a, modpow(b, c, mod-1), mod) << '\n';
    }
 
    return 0;
}