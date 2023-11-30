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

const int maxLen = 19;
const int maxDig = 10;

vi decompose(ll n) {
    vi digs;
    rep(i, 0, maxLen) {
        digs.push_back(n % 10);
        n /= 10;
    }
    reverse(all(digs));
    return digs;
}

ll solve(ll bound) {
    if(bound < 0) return 0;

    ll dp[maxLen][2][maxDig+1][2];
    memset(dp, -1, sizeof(dp));

    vi num = decompose(bound);

    auto calc = [&](int idx, int isEqual, int prvDig, int nonZero, auto &calc) -> ll {
        if(idx == maxLen) return 1;
        
        ll &cur = dp[idx][isEqual][prvDig][nonZero];
        if(cur != -1) return cur;

        cur = 0;
        assert(idx < sz(num));
        int upper = (isEqual ? num[idx]+1 : maxDig);
        rep(dig, 0, upper) {
            if(nonZero && dig == prvDig) continue;
            cur = cur + calc(idx+1, isEqual && dig == upper-1, dig, nonZero || dig != 0, calc);
        }

        return cur;
    };

    return calc(0, 1, 10, 0, calc);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    ll lo, hi; cin >> lo >> hi;
    cout << solve(hi) - solve(lo - 1) << '\n';

    return 0;
}