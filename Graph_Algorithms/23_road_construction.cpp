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

struct DSU {
    vi e;
    DSU(int n): e(n, -1) {}
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    int size(int x) { return -e[find(x)]; }
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(e[x] < e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;

    int numComps = n, maxComp = 1;
    DSU dsu(n);

    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        if(dsu.join(u, v)) {
            numComps--;
            maxComp = max(maxComp, dsu.size(u));
        }
        cout << numComps << ' ' << maxComp << '\n';
    }

    return 0;
}