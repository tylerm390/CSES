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
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    Tree<pii> elements;
    
    rep(i, 0, k)
        elements.insert(pii(arr[i], i));
    
    int prv = elements.find_by_order(k / 2)->first;
    
    ll cost = 0;
    rep(i, 0, k)
        cost += abs(arr[i] - prv);
    cout << cost << ' ';

    rep(i, 1, n - k + 1) {
        cost -= abs(arr[i-1] - prv);
        elements.erase(pii(arr[i-1], i-1));
        elements.insert(pii(arr[i+k-1], i+k-1));
        int cur = elements.find_by_order(k/2)->first;
        cost += abs(arr[i+k-1] - cur);
        if(k % 2 == 0) cost += cur - prv;
        prv = cur;
        cout << cost << ' ';
    }

    cout << '\n';

    return 0;
}