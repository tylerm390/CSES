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

    int n; cin >> n;

    vvi ans(1 << n, vi(n));
    ans[1][0] = 1;

    rep(i, 1, n) {
        rep(j, 0, (1 << i)) {
            ans[(1 << i) + j] = ans[(1 << i) - j - 1];
            ans[(1 << i) + j][i] = 1;
        }
    }

    rep(i, 0, 1 << n) {
        for(int j = n-1; j >= 0; j--)
            cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}