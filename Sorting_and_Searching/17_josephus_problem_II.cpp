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

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k; cin >> n >> k;

    Tree<int> rem;
    rep(i, 0, n) rem.insert(i);

    int cur = k;
    while(!rem.empty()) {
        cur %= sz(rem);
        int nxt = *rem.find_by_order(cur);
        cout << nxt + 1 << ' ';
        rem.erase(nxt);
        cur += k;   
    }
    cout << '\n';

    return 0;
}