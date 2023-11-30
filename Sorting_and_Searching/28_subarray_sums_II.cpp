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
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    map<ll, int> prefixFreq;
    ll ans = 0, prefix = 0;
    prefixFreq[0] = 1;
    rep(i, 0, n) {
        prefix += arr[i];
        ans += prefixFreq[prefix-x];
        prefixFreq[prefix]++;
    }

    cout << ans << '\n';

    return 0;
}