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
 
vvl operator*(vvl A, vvl B) {
    int n = sz(A);
    vvl C(n, vl(n));
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) 
        C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
    return C;
}
 
vl operator*(vvl A, vl b) {
    int n = sz(A);
    vl c(n);
    rep(i, 0, n) rep(j, 0, n)
        c[i] = (c[i] + A[i][j] * b[j] % mod) % mod;
    return c;
}
 
vvl operator^(vvl B, ll p) {
    int n = sz(B);
    vvl res(n, vl(n));
    rep(i, 0, n) res[i][i] = 1;
 
    while(p > 0) {
        if(p & 1) res = res * B;
        B = B*B;
        p >>= 1;
    }
 
    return res;
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    ll n; cin >> n;
 
    vvl mat = {
        {0, 1},
        {1, 1}
    };
 
    mat = mat ^ n;
 
    vl b = {0, 1};
    b = mat * b;
 
    cout << b[0] << '\n';
 
    return 0;
}