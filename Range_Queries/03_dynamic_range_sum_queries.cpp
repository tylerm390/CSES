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
using vii = vector<pii>;
using vvi = vector<vi>;
 
struct BIT {
    vector<ll> bit;
    BIT(int n): bit(n+1, 0) {}
    void update(int idx, int dif) {
        for(; idx < sz(bit); idx += (idx & (-idx)))
            bit[idx] += dif;
    }
    ll query(int idx) {
        ll ans = 0;
        for(; idx > 0; idx -= (idx & (-idx)))
            ans += bit[idx];
        return ans;
    }
    ll query(int L, int R) {
        return query(R+1) - query(L);
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n, q; cin >> n >> q;
    BIT bit(n);
    vi arr(n);
 
    rep(i, 0, n) {
        int v; cin >> v;
        bit.update(i+1, v);
        arr[i] = v;
    }
 
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int idx, val;
            cin >> idx >> val;
            bit.update(idx, val - arr[idx-1]);
            arr[idx-1] = val;
        }
        else {
            int L, R; cin >> L >> R;
            cout << bit.query(L-1, R-1) << '\n';
        }
    }
 
    return 0;
}