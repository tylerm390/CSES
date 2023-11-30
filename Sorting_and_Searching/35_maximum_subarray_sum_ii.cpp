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

    int n, L, R; cin >> n >> L >> R;
    vi arr(n); 
    for(int &ai: arr) cin >> ai;

    vector<ll> sums(n+1);
    rep(i, 0, n)
        sums[i+1] = sums[i] + arr[i];

    multiset<ll> ms;
    ll ans = -1e18;
    rep(i, L, n+1) {
        ms.insert(sums[i-L]);
        ans = max(ans, sums[i] - *ms.begin());
        if(i >= R)
            ms.erase(ms.find(sums[i-R]));
    }

    cout << ans << '\n';

    return 0;
}