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
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    ll tot = accumulate(all(arr), 0LL);

    ll best = 1e16;
    rep(mask, 0, 1 << n) {
        ll sum = 0;
        rep(i, 0, n)
            if((mask >> i) & 1)
                sum += arr[i];
        best = min(best, abs(tot - 2*sum));
    }

    cout << best << '\n';

    return 0;
}