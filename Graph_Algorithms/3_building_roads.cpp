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

struct DS {
    vi p;
    DS(int n): p(n, -1) {}
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;
    DS ds(n);

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        ds.join(u, v);
    }

    vi pars;
    rep(i, 0, n)
        if(i == ds.find(i))
            pars.push_back(i + 1    );
    
    cout << sz(pars) - 1 << '\n';
    rep(i, 0, sz(pars)-1)
        cout << pars[i] << ' ' << pars[i+1] << '\n';

    return 0;
}