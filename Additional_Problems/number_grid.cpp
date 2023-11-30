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

    int n, m; cin >> n >> m; n--, m--;

    ll res = 0;
    rep(i, 0, 31) {
        int x = n / (1 << i);
        int y = m / (1 << i);
        if((x + y) % 2 == 1)
            res += 1 << i;
    }

    cout << res << '\n';

    return 0;
}