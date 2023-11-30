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

    int n, x; cin >> n >> x;
    vi h(n), s(n);
    for(int &hi: h) cin >> hi;
    for(int &si: s) cin >> si;

    vi dp(x+1, 0);

    rep(i, 0, n)
        for(int j = x; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
    
    cout << dp[x] << '\n';

    return 0;
}