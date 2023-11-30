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

const int mod = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;

    int ans = 1;
    rep(i, 0, n) ans = (ans * 2) % mod;

    cout << ans << '\n';

    return 0;
}