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
using vvii = vector<vii>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;

    if(n == 1) {
        cout << "01\n";
        return 0;
    }

    vvii adj(1 << (n-1));
    int m = 0;
    rep(mask, 0, 1 << (n-1)) {
        rep(i, 0, 2) {
            int nxt = (mask << 1) | i;
            nxt &= (1 << (n-1)) - 1;
            adj[mask].emplace_back(nxt, m++);
        }
    }

    deque<int> s = {0};
    vi idxs(1 << (n-1)), deg(1 << (n-1)), seen(m);
    vi euler;
    while(!s.empty()) {
        auto cur = s.back();
        if(idxs[cur] == sz(adj[cur])) {
            euler.push_back(cur);
            s.pop_back();
            continue;
        }
        auto [nxt, id] = adj[cur][idxs[cur]++];
        if(seen[id]) continue;
        seen[id] = 1;
        deg[cur]--, deg[nxt]++;
        s.push_back(nxt);
    }

    string res = "";
    rep(i, 0, n-2) res += "0";

    reverse(all(euler));
    for(int i: euler)
        res += to_string(i & 1);
    
    cout << res << '\n';

    return 0;
}