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
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) -> bool {
        if(arr[i] == arr[j]) return i > j;
        return arr[i] < arr[j];
    });  

    set<int> idxs;
    vi ans(n, -1);
    for(int i: ord) {
        idxs.insert(i);
        auto it = idxs.find(i);
        if(it == idxs.begin()) continue;
        ans[i] = *prev(it);
    }

    for(int i: ans)
        cout << i+1 << ' ';
    cout << '\n';

    return 0;
}