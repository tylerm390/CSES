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
    vi arr(n+1); 
    iota(all(arr), 0);
    
    rep(i, 0, n-1) {
        int v; cin >> v;
        arr[v] = 0;
    }

    cout << *max_element(all(arr)) << '\n';

    return 0;
}