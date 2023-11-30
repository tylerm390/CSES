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
 
const int inf = 1e9, maxDim = 501;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m; cin >> n >> m;
 
    vvi dp(n+1, vi(m+1, inf));
    rep(i, 0, min(n, m) + 1)
        dp[i][i] = 0;
 
    rep(i, 0, n+1) {
        rep(j, 0, m+1) {
            if(i == j) continue;
            rep(k, 1, i)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            rep(k, 1, j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
    }
 
    cout << dp[n][m] << '\n';
 
    return 0;
}