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

    if(1 < n && n < 4) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    rep(i, 1, n/2+1)
        cout << 2*i << ' ';
    
    rep(i, 1, (n+1)/2+1)
        cout << 2*i-1 << ' ';
    
    cout << '\n';

    return 0;
}