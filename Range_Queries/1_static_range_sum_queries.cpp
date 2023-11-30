#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;
using vvi = vector<vi>;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n, q; cin >> n >> q;
    vll sums(n);
    for(ll &i: sums)
        cin >> i;
 
    partial_sum(all(sums), sums.begin());
 
    while(q--) {
        int i, j; cin >> i >> j;
        ll ans = sums[j-1];
        if(i != 1) ans -= sums[i - 2];
        cout << ans << '\n';
    }
 
    return 0;
}