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

void solve() {
    ll k; cin >> k; k--;

    ll pow10 = 1;
    int e = 1;
    while(k >= e*pow10*9)
        k -= e*pow10*9, pow10 *= 10, e++;
    
    ll num = pow10 + k / e;
    cout << to_string(num)[k % e] << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int q; cin >> q;
    while(q--) solve();

    return 0;
}