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

    multiset<int> towers;
    rep(i, 0, n) {
        int v; cin >> v;
        towers.insert(v);

        auto it = towers.upper_bound(v);

        if(it == towers.end())
            continue;

        towers.erase(it);
    }

    cout << sz(towers) << '\n';

    return 0;
}