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

const int off = 1e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;
    vi arr(n);
    for(int &ai: arr) cin >> ai, ai = (ai + off) % n;

    vi modFreq(n);
    modFreq[0] = 1;
    ll ans = 0, prefixMod = 0;
    rep(i, 0, n) {
        prefixMod = (prefixMod + arr[i]) % n;
        ans += modFreq[prefixMod];
        modFreq[prefixMod]++;
    }
    cout << ans << '\n';

    return 0;
}