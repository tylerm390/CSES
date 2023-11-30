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
    vi dp(n+1);
    dp[0] = 1;

    rep(i, 1, n+1)
        rep(j, 1, min(i, 6) + 1)
            dp[i] = (dp[i] + dp[i-j]) % mod;
    
    cout << dp[n] << '\n';

    return 0;
}