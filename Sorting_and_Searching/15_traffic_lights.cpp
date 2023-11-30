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

    int x, n; cin >> x >> n;

    set<int> locs;
    locs.emplace(0);
    locs.emplace(x);

    auto cmpSize = [&](pii a, pii b) -> bool {
        if(a.second - a.first == b.second - b.first)
            return a < b;
        return a.second - a.first > b.second - b.first;
    };
    set<pii, decltype(cmpSize)> rangesBySize(cmpSize);
    rangesBySize.emplace(0, x);

    rep(i, 0, n) {
        int p; cin >> p;
        locs.emplace(p);

        auto it = locs.find(p);
        int s = *prev(it);
        int e = *next(it);

        rangesBySize.erase(pii(s, e));
        rangesBySize.emplace(s, p);
        rangesBySize.emplace(p, e);

        auto [bestS, bestE] = *rangesBySize.begin();
        cout << bestE - bestS << ' ';
    }
    cout << '\n';

    return 0;
}