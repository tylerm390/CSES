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
    vii ranges(n);
    for(auto &[s, e]: ranges) cin >> s >> e;

    sort(all(ranges), [&](pii a, pii b) -> bool {
        return tie(a.second, a.first) < tie(b.second, b.first);
    });

    int cnt = 0;
    rep(i, 0, n) {
        cnt++;
        int j = i+1;
        while(j < n && ranges[j].first < ranges[i].second)
            j++;
        i = j-1;
    }

    cout << cnt << '\n';

    return 0;
}