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
    for(int &ai: arr) cin >> ai, ai--;

    vi idx(n);
    rep(i, 0, n)
        idx[arr[i]] = i;

    int cnt = 1;
    rep(i, 1, n)
        cnt += idx[i-1] > idx[i];

    cout << cnt << '\n';

    return 0;
}