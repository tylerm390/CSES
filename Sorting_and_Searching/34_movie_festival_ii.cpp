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
    vii ranges(n);
    for(auto &[L, R]: ranges)
        cin >> L >> R;
    
    sort(all(ranges), [&](pii a, pii b) -> bool {
        return a.second < b.second;
    });

    map<int, int> open;
    open[0] = k;

    int cnt = 0;
    for(auto [L, R]: ranges) {
        auto it = open.upper_bound(L);
        if(it == open.begin()) continue;
        cnt++;
        int t = prev(it)->first;
        open[R]++;
        open[t]--;
        if(open[t] == 0)
            open.erase(t);
    }

    cout << cnt << '\n';

    return 0;
}