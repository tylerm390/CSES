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

    int n; cin >> n;
    vi coins(n);
    for(int &ci: coins) cin >> ci;

    int maxVal = accumulate(all(coins), 0);

    vector<bool> dp(maxVal + 1);
    dp[0] = true;

    for(int c: coins)
        for(int i = maxVal; i >= c; i--)
            dp[i] = dp[i] || dp[i-c];
    
    cout << accumulate(all(dp), 0) - 1 << '\n';
    rep(i, 1, maxVal+1)
        if(dp[i])
            cout << i << ' ';
    cout << '\n';

    return 0;
}