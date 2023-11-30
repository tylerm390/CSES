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

const int inf = 1e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    string s, t; cin >> s >> t;
    int n = sz(s), m = sz(t);

    vvi dp(n+1, vi(m+1, inf));
    dp[n][m] = 0;

    for(int i = n; i >= 0; i--) {
        for(int j = m; j >= 0; j--) {
            if(i == n && j == m) continue;

            if(i < n) 
                dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
            if(j < m)
                dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
            if(i < n && j < m)
                dp[i][j] = min(dp[i][j], dp[i+1][j+1] + (s[i] != t[j])); 
        }
    }

    cout << dp[0][0] << '\n';

    return 0;
}