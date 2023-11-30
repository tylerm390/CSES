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

struct BIT {
	vector<ll> s;
	BIT(int n) : s(n) {}
	void update(int pos, ll dif) {
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) {
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q; cin >> n >> q;

    vi vals(n);
    for(int &vi: vals) cin >> vi;

    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi pre(n), post(n);
    int t = 0;
    auto dfs = [&](int cur, int prv, auto &dfs) -> void {
        pre[cur] = t++;
        for(int nxt: adj[cur]) if(nxt != prv)
            dfs(nxt, cur, dfs);
        post[cur] = t++;
    };
    dfs(0, -1, dfs);

    BIT euler(2*n);
    rep(i, 0, n) {
        euler.update(pre[i], vals[i]);
        euler.update(post[i], -vals[i]);
    }

    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int u, x; cin >> u >> x; u--;
            int dif = x - vals[u];
            euler.update(pre[u], dif);
            euler.update(post[u], -dif);
            vals[u] = x;
        }
        else {
            int u; cin >> u; u--;
            cout << euler.query(pre[u]+1) << '\n';
        }
    }

    return 0;
}