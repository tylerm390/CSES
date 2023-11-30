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

    vvi transitions(1 << n);
    rep(mask, 0, 1 << n) {
        rep(nxtMask, 0, 1 << n) {
            bool good = true;
            rep(i, 0, n) {
                if(((mask >> i) & 1) == 1) {
                    if(((nxtMask >> i) & 1) == 1) {
                        good = false;
                        break;
                    }
                    continue;
                }

                if(((nxtMask >> i) & 1) == 0) {
                    if(i == n-1 || (((mask >> (i+1)) & 1) == 1 || ((nxtMask >> (i+1)) & 1) == 1)) {
                        good = false;
                        break;
                    }
                    i++;
                    continue;
                }
            }
            
            if(good)
                transitions[mask].push_back(nxtMask);
        }
    }

    vvi dp(1 << n, vi(m, -1));
    auto solve = [&](int mask, int col, auto &solve) -> int {
        if(col == m) return mask == 0;

        auto &cur = dp[mask][col];
        if(cur != -1) return cur;

        cur = 0;
        for(int nxtMask: transitions[mask])
            cur = (cur + solve(nxtMask, col+1, solve)) % mod;
        
        return cur;
    };

    cout << solve(0, 0, solve) << '\n';

    return 0;
}