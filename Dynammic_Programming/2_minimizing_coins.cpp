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

    int n, x; cin >> n >> x;
    vi coins(n);
    for(int &ci: coins) cin >> ci;
    
    vi dp(x+1, inf);
    dp[0] = 0;

    rep(i, 1, x+1)
        for(int c: coins)
            if(i - c >= 0)
                dp[i] = min(dp[i], dp[i - c] + 1);
    
    if(dp[x] == inf)
        cout << -1 << '\n';
    else
        cout << dp[x] << '\n';

    return 0;
}