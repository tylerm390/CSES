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

    int n, k; cin >> n >> k;
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    auto test = [&](ll maxSum) -> bool {
        int cnt = 1;
        ll sum = 0;
        rep(i, 0, n) {
            if(arr[i] + sum <= maxSum) {
                sum += arr[i];
                continue;
            }
            sum = arr[i];
            assert(sum <= maxSum);
            cnt++;
        }
        return cnt <= k;
    };

    ll lo = *max_element(all(arr)), hi = 1e15, ans = hi;
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