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

    int n, m; cin >> n >> m;
    
    map<int, int> tickets;
    rep(i, 0, n) {
        int v; cin >> v;
        tickets[v]++;
    }

    rep(i, 0, m) {
        int lim; cin >> lim;
        auto it = tickets.upper_bound(lim);
        if(it == tickets.begin()) {
            cout << -1 << '\n';
            continue;
        }
        int val = prev(it) -> first;
        cout << val << '\n';
        tickets[val]--;
        if(!tickets[val]) tickets.erase(val);
    }

    return 0;
}