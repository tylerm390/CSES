#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define sz(x) (x).size()
#define all(x) begin(x), end(x)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    vvi adj(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v, u--, v--;
        adj[u].push_back(v);
    }

    vector<bool> seen(n), onStack(n);
    vi lowlink(n), preorder(n), comp(n, -1);
    stack<int> s;

    int curPre = 0, curComp = 0;
    auto dfs = [&](int cur, auto &dfs) -> void {
        lowlink[cur] = preorder[cur] = curPre++;
        s.push(cur);
        onStack[cur] = true;
        for(int nxt: adj[cur]) {
            if(onStack[nxt])
                lowlink[cur] = min(lowlink[cur], preorder[nxt]);
            if(seen[nxt])
                continue;
            seen[nxt] = true;
            dfs(nxt, dfs);
            lowlink[cur] = min(lowlink[cur], lowlink[nxt]);
        }

        if(preorder[cur] == lowlink[cur]) {
            while(s.top() != cur) {
                comp[s.top()] = curComp;
                onStack[s.top()] = false;
                s.pop();
            }
            comp[cur] = curComp++;
            onStack[cur] = false;
            s.pop();
        }
    };
    

    rep(i, 0, n) {
        if(!seen[i]) {
            seen[i] = true;
            dfs(i, dfs);
        }
    }

    cout << curComp << '\n';
    for(int c: comp)
        cout << c+1 << ' ';
    cout << '\n';

    return 0;
}