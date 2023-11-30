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
    ll dot(pt p) { return x * p.x + y * p.y; }
};

bool onSeg(pt s, pt e, pt p) {
    return s.cross(e, p) == 0 && (p-s).dot(p-e) <= 0;
}

#define sgn(x) ((x > 0) - (x < 0))

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        pt a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        
        int s1 = sgn(a.cross(b, c)), s2 = sgn(a.cross(b, d)),
            s3 = sgn(c.cross(d, a)), s4 = sgn(c.cross(d, b));

        bool intersects = false;
        if(s1*s2 < 0 && s3*s4 < 0)
            intersects = true;
        
        if(onSeg(a, b, c)) intersects = true;
        if(onSeg(a, b, d)) intersects = true;
        if(onSeg(c, d, a)) intersects = true;
        if(onSeg(c, d, b)) intersects = true;

        if(intersects) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}