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

    int n; cin >> n;
    vector<int> dp(n+1, inf);
    dp[0] = 0;

    rep(i, 1, n+1)
        for(char c: to_string(i))
            dp[i] = min(dp[i], dp[i - c + '0'] + 1);
    
    cout << dp[n] << '\n';

    return 0;
}