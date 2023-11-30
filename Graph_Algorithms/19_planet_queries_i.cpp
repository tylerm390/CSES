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

int maxJumps = 31;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q; cin >> n >> q;

    vvi jmp(maxJumps, vi(n, -1));

    rep(i, 0, n)
        cin >> jmp[0][i], jmp[0][i]--;
    
    rep(i, 1, maxJumps) {
        rep(j, 0, n) {
            int prv = jmp[i-1][j];
            if(prv == -1) continue;
            jmp[i][j] = jmp[i-1][prv];
        }
    }

    rep(i, 0, q) {
        int x, k; cin >> x >> k; x--;
        rep(i, 0, maxJumps)
            if((k >> i) & 1)
                x = jmp[i][x];
        cout << x + 1 << '\n';
    }

    return 0;
}