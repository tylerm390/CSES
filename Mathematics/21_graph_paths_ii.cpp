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
using vl = vector<ll>;
using vvl = vector<vl>;
 
const ll mod = 1e9+7;
const ll inf = 2e18;
 
vvl operator*(vvl A, vvl B) {
    int n = sz(A);
    vvl C(n, vl(n, inf));
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) 
        C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
    return C;
}
 
vvl operator^(vvl B, ll p) {
    int n = sz(B);
    vvl res(n, vl(n, inf));
    rep(i, 0, n) res[i][i] = 0;
 
    while(p > 0) {
        if(p & 1) res = res * B;
        B = B*B;
        p >>= 1;
    }
 
    return res;
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n, m, k; cin >> n >> m >> k;
    vvl mat(n, vl(n, inf));
    rep(i, 0, m) {
        int u, v; ll w; cin >> u >> v >> w; u--, v--;
        mat[v][u] = min(mat[v][u], w);
    }
 
    mat = mat ^ k;
 
    if(mat[n-1][0] == inf) cout << -1 << '\n';
    else cout << mat[n-1][0] << '\n';
 
    return 0;
}