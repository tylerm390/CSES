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
    vi vals(n);
    for(int &vi: vals) cin >> vi;

    vvi adj(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }

    vector<int> preorder(n, -1), lowlink(n, -1);
    vector<int> seen(n);
    vector<int> compId(n);
    int nComps = 0, t = 0;
    stack<int> s;

    auto dfs = [&](int cur, auto &dfs) -> void {
        preorder[cur] = lowlink[cur] = t++;
        s.push(cur);
        for(int nxt: adj[cur]) {
            if(seen[nxt] == 1)
                lowlink[cur] = min(lowlink[cur], preorder[nxt]);
            if(seen[nxt]) continue;
            seen[nxt] = 1;
            dfs(nxt, dfs);
            lowlink[cur] = min(lowlink[cur], lowlink[nxt]);
        }

        if(lowlink[cur] == preorder[cur]) {
            int top;
            do {    
                top = s.top(); s.pop();
                compId[top] = nComps;
                seen[top] = 2;
            } while(top != cur);
            nComps++;
        }
    };

    rep(i, 0, n) 
        if(!seen[i])
            dfs(i, dfs);

    vvi meta(nComps);
    vector<ll> metaVals(nComps);
    rep(i, 0, n) {
        for(int j: adj[i])
            if(compId[i] != compId[j])
                meta[compId[i]].push_back(compId[j]);
        metaVals[compId[i]] += vals[i];
    }
    
    rep(i, 0, nComps) {
        sort(all(meta[i]));
        meta[i].erase(unique(all(meta[i])), meta[i].end());
    }

    vector<ll> dp(nComps, -1);
    auto solve = [&](int cur, auto &solve) -> ll {
        if(dp[cur] != -1) return dp[cur];
        dp[cur] = 0;
        for(int nxt: meta[cur])
            dp[cur] = max(dp[cur], solve(nxt, solve));
        dp[cur] += metaVals[cur];
        return dp[cur];
    };

    ll res = 0;
    rep(i, 0, nComps)
        res = max(res, solve(i, solve));
    
    cout << res << '\n';

    return 0;
}