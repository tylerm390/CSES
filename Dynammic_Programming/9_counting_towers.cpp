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

const int maxVal = 1e6, mod = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    vector<vector<ll>> dp(maxVal+1, vector<ll>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;

    rep(i, 2, maxVal+1) {
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % mod;
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }

    return 0;
}