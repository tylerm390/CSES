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

    int n, maxW;
    cin >> n >> maxW;
    vi weights(n);
    for(int &wi: weights)
        cin >> wi;
    
    vii dp(1 << n, pii(-1, -1));
    
    auto solve = [&](int mask, auto &solve) -> pii {
        if(mask == 0) return pii(0, 0);

        auto &cur = dp[mask];
        if(cur != pii(-1, -1)) return cur;

        cur = pii(n+1, 0);
        rep(i, 0, n) {
            if(!((mask >> i) & 1)) continue;
            auto [prvRides, prvWt] = solve(mask - (1 << i), solve);
            prvWt += weights[i];
            if(prvWt > maxW)
                prvRides++, prvWt = weights[i];
            pii prv = pii(prvRides, prvWt);
            if(prv < cur)
                cur = prv;
        }

        return cur;
    };

    auto [ans, wt] = solve((1 << n) - 1, solve);
    ans += wt != 0;
    cout << ans << '\n';

    return 0;
}