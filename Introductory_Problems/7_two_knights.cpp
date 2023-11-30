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

    int n; cin >> n;

    rep(i, 1, n+1) {
        ll nSq = i*i;
        ll choices = nSq * (nSq - 1) / 2;
        
        ll bad = 4 * (i - 1) * (i - 2);
        choices -= bad;

        cout << choices << '\n';
    }

    return 0;
}