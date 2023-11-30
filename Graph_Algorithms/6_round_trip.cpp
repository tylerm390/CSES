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

    int n, m; cin >> n >> m;
    vvi adj(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    stack<int> s;
    vi seen(n);
    
    auto dfs = [&](int cur, int prv, auto &dfs) -> vi {
        if(seen[cur]) {
            vi ans = {cur};
            int top;
            
            do {
                top = s.top(); s.pop();
                ans.push_back(top);
            } while(top != cur);

            return ans;
        }

        s.push(cur);
        seen[cur] = true;

        for(int nxt: adj[cur]) if(prv != nxt) {
            vi ans = dfs(nxt, cur, dfs);
            if(!ans.empty())
                return ans; 
        }

        s.pop();
        
        return vi();
    };

    vi ans;

    rep(i, 0, n) {
        if(seen[i]) continue;
        ans = dfs(i, -1, dfs);
        if(!ans.empty()) break;
    }

    if(ans.empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << sz(ans) << '\n';
    for(int u: ans)
        cout << u + 1 << ' ';
    cout << '\n';

    return 0;
}