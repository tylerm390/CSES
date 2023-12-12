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
 
struct SparseTable {
    vvi st;
    SparseTable(vi &arr): st(1, arr) {
        for(int pw = 1, k = 1; pw * 2 <= sz(arr); pw *= 2, k++) {
            st.emplace_back(sz(arr) - pw*2 + 1);
            rep(j, 0, sz(st[k]))
                st[k][j] = min(st[k-1][j], st[k-1][j + pw]);
        }
    }
    int query(int l, int r) {
        int dep = 31 - __builtin_clz(r - l + 1);
        return min(st[dep][l], st[dep][r - (1 << dep) + 1]);
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n, q; cin >> n >> q;
    vi arr(n);
    for(int &ai: arr) cin >> ai;
 
    SparseTable st(arr);
 
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l-1, r-1) << '\n';
    }
 
    return 0;
}