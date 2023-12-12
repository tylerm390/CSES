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
    vector<string> grid(n);
    for(auto &s: grid) cin >> s;

    vvi dp(n, vi(n));
    dp[0][0] = grid[0][0] == '.';

    rep(i, 0, n) {
        rep(j, 0, n) {
            if((i == 0 && j == 0) || grid[i][j] == '*') continue;
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[n-1][n-1] << '\n';

    return 0;
}