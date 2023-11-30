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
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
    ll cross(pt p) { return x * p.y - y * p.x; }
    ll cross(pt p, pt q) { return (p - *this).cross(q - *this); }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        pt s, e, p;
        cin >> s.x >> s.y >> e.x >> e.y >> p.x >> p.y;
        ll cross = s.cross(e, p);
        if(cross > 0) cout << "LEFT\n";
        else if(cross < 0) cout << "RIGHT\n";
        else cout << "TOUCH\n";
    }

    return 0;
}