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
 
    int n, a, b;
    cin >> n >> a >> b;
 
    vector<vector<double>> dp(n+1, vector<double>(b+1, 0));
    dp[0][0] = 1;
 
    rep(i, 0, n) rep(j, 1, 7)
        rep(k, 0, b-j+1)
            dp[i+1][k+j] += dp[i][k] / 6.0;
 
    double res = 0;
    rep(i, a, b+1)
        res += dp[n][i];
 
    cout << setprecision(6) << fixed << res << '\n';
 
    return 0;
}