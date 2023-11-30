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

using range = tuple<int, int, int>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;
    vector<range> ranges(n);
    for(auto &[s, e, p]: ranges)
        cin >> s >> e >> p;
    sort(all(ranges));

    vector<ll> dp(n, -1);

    auto solve = [&](int idx, auto &solve) -> ll {
        if(idx == n) return 0;

        ll &cur = dp[idx];
        if(cur != -1) return cur;

        ll leave = solve(idx+1, solve);

        auto [s, e, p] = ranges[idx];
        
        auto it = lower_bound(all(ranges), range(e, 1e9, 1e9));
        int nxt = it - ranges.begin();

        ll take = solve(nxt, solve) + p;

        return cur = max(leave, take);
    };

    cout << solve(0, solve) << '\n';

    return 0;
}