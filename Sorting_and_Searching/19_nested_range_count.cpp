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
    vii ranges(n);
    for(auto &[s, e]: ranges) cin >> s >> e;

    // count ranges contained by this range
    {
        vi ord(n);
        iota(all(ord), 0);
        
        sort(all(ord), [&](int i, int j) -> bool {
            if(ranges[i].first == ranges[j].first)
                return ranges[i].second < ranges[j].second;
            return ranges[i].first > ranges[j].first;
        });
        
        vi ans(n);
        Tree<pii> ends;
        for(int i: ord) {
            auto [s, e] = ranges[i];
            ans[i] = ends.order_of_key(pii(e, n+1));
            ends.insert(pii(e, i));
        }

        rep(i, 0, n)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    // count number of ranges containing this range
    {
        vi ord(n);
        iota(all(ord), 0);
        
        sort(all(ord), [&](int i, int j) -> bool {
            if(ranges[i].first == ranges[j].first)
                return ranges[i].second > ranges[j].second;
            return ranges[i].first < ranges[j].first;
        });
        
        vi ans(n);
        Tree<pii> ends;
        for(int i: ord) {
            auto [s, e] = ranges[i];
            ans[i] = sz(ends) - ends.order_of_key(pii(e, 0));
            ends.insert(pii(e, i));
        }

        rep(i, 0, n)
            cout << ans[i] << ' ';
        cout << '\n';


    }

    return 0;
}