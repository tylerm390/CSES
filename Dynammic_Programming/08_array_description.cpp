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

    int n, m; cin >> n >> m;
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    vvi dp(n, vi(m+1, -1));
    auto solve = [&](int idx, int val, auto &solve) -> int {
        if(val == 0 || val == m+1) return 0;
        if(arr[idx] != 0 && arr[idx] != val) return 0;
        if(idx == n-1) return 1;

        int &cur = dp[idx][val];
        if(cur != -1) return cur;

        cur = 0;
        rep(d, -1, 2)
            cur = (cur + solve(idx+1, val + d, solve)) % mod;
        
        return cur;
    };

    int ans = 0;
    if(arr[0] == 0) {
        rep(i, 1, m+1)
            ans = (ans + solve(0, i, solve)) % mod;
    }
    else
        ans = solve(0, arr[0], solve);

    cout << ans << '\n';

    return 0;
}