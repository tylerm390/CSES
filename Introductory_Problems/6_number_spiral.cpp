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

    int t; cin >> t;
    while(t--) {
        int r, c; cin >> r >> c;

        ll ans = (max(r, c) - 1) * (ll) (max(r, c) - 1);
        if(ans % 2 == 0) {
            if(c < r)
                ans += c;
            else
                ans += 2*c - r;
        }
        else {
            if(r < c)
                ans += r;
            else
                ans += 2*r - c;
        }
        
        cout << ans << '\n';
    }

    return 0;
}