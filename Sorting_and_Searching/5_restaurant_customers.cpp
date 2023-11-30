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
    vii events;
    rep(i, 0, n) {
        int s, e; cin >> s >> e;
        events.emplace_back(s, 1);
        events.emplace_back(e+1, -1);
    }

    sort(all(events));

    int cnt = 0, ans = 0;
    for(auto [_, d]: events)
        cnt += d, ans = max(ans, cnt);
    
    cout << ans << '\n';

    return 0;
}