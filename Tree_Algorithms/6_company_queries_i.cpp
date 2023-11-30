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

    int n, q; cin >> n >> q;

    int maxJump = __lg(n) + 1;
    vvi jmp(maxJump, vi(n, -1));
    rep(i, 1, n)
        cin >> jmp[0][i], jmp[0][i]--;

    rep(i, 1, maxJump) {
        rep(j, 0, n) {
            int prv = jmp[i-1][j];
            if(prv == -1) continue;
            jmp[i][j] = jmp[i-1][prv];
        }
    }

    rep(i, 0, q) {
        int k, x; cin >> x >> k; x--;
        rep(i, 0, maxJump)
            if(x != -1 && (k >> i) & 1)
                x = jmp[i][x];
        
        if(x != -1) x++;
        cout << x << '\n';
    }

    return 0;
}