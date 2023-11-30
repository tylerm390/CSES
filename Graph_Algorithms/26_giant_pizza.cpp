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
 
const ll mod = 1e9+7;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int nPeople, nToppings; cin >> nPeople >> nToppings;
 
    int n = 2 * nToppings;
    vvi adj(n);
    rep(i, 0, nPeople) {
        char add1, add2;
        int t1, t2;
        cin >> add1 >> t1 >> add2 >> t2;
        int u = (t1 - 1) * 2 + (add1 == '-');
        int v = (t2 - 1) * 2 + (add2 == '-');
        adj[u ^ 1].push_back(v);
        adj[v ^ 1].push_back(u);
    }
 
    vector<int> preorder(n, -1), lowlink(n, -1);
    vector<int> seen(n);
    vector<int> compId(n);
    int nComps = 0, t = 0;
    vi res(nToppings, -1);
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
                if(res[top >> 1] == -1)
                    res[top >> 1] = top & 1;
            } while(top != cur);
            nComps++;
        }
    };
    
    rep(i, 0, n)
        if(!seen[i])
            dfs(i, dfs);
 
    bool good = true;
    rep(i, 0, nToppings) {
        if(compId[2*i] == compId[2*i + 1]) {
            good = false;
            break;
        }
    }
 
    if(!good) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    rep(i, 0, nToppings)
        cout << (res[i] == 0 ? '+' : '-') << ' ';
    cout << '\n';
 
    return 0;
}