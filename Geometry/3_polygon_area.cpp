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

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0): x(x), y(y) {}
    ll cross(pt p) { return x * p.y - y * p.x; }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;
    vector<pt> poly(n);
    for(auto &[x, y]: poly) cin >> x >> y;

    ll A = 0;
    rep(i, 0, n)
        A += poly[i].cross(poly[(i+1)%n]);
    
    cout << abs(A) << '\n';

    return 0;
}