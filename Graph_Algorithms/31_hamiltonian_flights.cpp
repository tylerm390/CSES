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
 
const int mod = 1e9 + 7, maxNodes = 20;
 
int adj[maxNodes][maxNodes];
int dp[maxNodes][1 << maxNodes];
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m; cin >> n >> m;
 
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u][v]++;
    }
 
    int maxMask = (1 << n) - 1;
    dp[n-1][maxMask] = 1;
 
    for(int mask = maxMask-1; mask >= 1; mask--) {
        for(int cur = 0; cur < n; cur++) {
            if(((mask >> cur) & 1) == 0) continue; 
            for(int nxt = 0; nxt < n; nxt++) {
                if((mask >> nxt) & 1) continue;
                ll nxtRes = dp[nxt][mask | (1 << nxt)];
                dp[cur][mask] = (dp[cur][mask] + (adj[cur][nxt] * nxtRes)) % mod;
            }
        }
    }
 
    cout << dp[0][1] << '\n';
 
    return 0;
}