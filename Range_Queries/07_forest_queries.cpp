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

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q; cin >> n >> q;
    vvi grid(n, vi(n));
    rep(i, 0, n) {
        string s; cin >> s;
        rep(j, 0, n)
            grid[i][j] = s[j] == '*';
    }

    vvi psum(n, vi(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            psum[i][j] = grid[i][j];
            if(i > 0) psum[i][j] += psum[i-1][j];
            if(j > 0) psum[i][j] += psum[i][j-1];
            if(i > 0 && j > 0) psum[i][j] -= psum[i-1][j-1];
        }
    }

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int res = psum[x2][y2];
        if(x1 > 0) res -= psum[x1-1][y2];
        if(y1 > 0) res -= psum[x2][y1-1];
        if(x1 > 0 && y1 > 0) res += psum[x1-1][y1-1];
        cout << res << '\n';
    }

    return 0;
}