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
    
    for(int i = 0, j = k; j < n; i++, j++) {
        cout << elements.find_by_order((k-1)/2)->first << ' ';
        elements.insert(pii(arr[j], j));
        elements.erase(pii(arr[i], i));
    }

    cout << elements.find_by_order((k-1)/2)->first << '\n';

    return 0;
}