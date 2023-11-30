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

    int n, t; cin >> n >> t;
    vi times(n);
    for(int &ti: times) cin >> ti;

    auto test = [&](ll duration) -> bool {
        __int128_t amtMade = 0;
        rep(i, 0, n)
            amtMade += duration / times[i];
        return amtMade >= t;
    };

    ll lo = 0, hi = ((ll)1e18) + 10, ans = hi;
    while(lo <= hi) {
        ll md = (lo + hi) >> 1;
        if(test(md))
            hi = md-1, ans = md;
        else
            lo = md+1;
    }

    cout << ans << '\n';

    return 0;
}