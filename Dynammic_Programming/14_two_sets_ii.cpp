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
    int tot = n * (n + 1) / 2;

    if(tot % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int tar = tot / 2;
    vi dp(tar + 1);
    dp[0] = 1;
    
    rep(i, 1, n)
        for(int j = tar; j >= i; j--)
            dp[j] = (dp[j] + dp[j-i]) % mod;

    cout << dp[tar] << '\n';

    return 0;
}