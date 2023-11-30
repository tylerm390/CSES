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

    vi lis;
    rep(i, 0, n) {
        int v; cin >> v;
        auto it = lower_bound(all(lis), v);
        if(it == lis.end())
            lis.push_back(v);
        else
            *it = v;
    }

    cout << sz(lis) << '\n';

    return 0;
}