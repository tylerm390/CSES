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

    int n; cin >> n;

    Tree<pii> arr;
    rep(i, 0, n) {
        int v; cin >> v;
        arr.insert(pii(i, v));
    }

    rep(_, 0, n) {
        int idx; cin >> idx; idx--;
        auto [i, v] = *arr.find_by_order(idx);
        cout << v << ' ';
        arr.erase(arr.find_by_order(idx));
    }
    cout << '\n';

    return 0;
}