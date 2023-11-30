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
    vii ranges(n);
    for(auto &[s, e]: ranges) cin >> s >> e;

    // check if current range contains some other range
    {
        vi ord(n);
        iota(all(ord), 0);
        
        sort(all(ord), [&](int i, int j) -> bool {
            if(ranges[i].first == ranges[j].first)
                return ranges[i].second < ranges[j].second;
            return ranges[i].first > ranges[j].first;
        });
        
        vi ans(n);
        int minEnd = 1e9 + 10;
        for(int i: ord) {
            auto [s, e] = ranges[i];
            if(minEnd <= e)
                ans[i] = 1;
            minEnd = min(minEnd, e);
        }

        rep(i, 0, n)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    // check if current range is contained by some other range
    {
        vi ord(n);
        iota(all(ord), 0);
        
        sort(all(ord), [&](int i, int j) -> bool {
            if(ranges[i].first == ranges[j].first)
                return ranges[i].second > ranges[j].second;
            return ranges[i].first < ranges[j].first;
        });
        
        vi ans(n);
        int maxEnd = 0;
        for(int i: ord) {
            auto [s, e] = ranges[i];
            if(e <= maxEnd)
                ans[i] = 1;
            maxEnd = max(maxEnd, e);
        }

        rep(i, 0, n)
            cout << ans[i] << ' ';
        cout << '\n';


    }

    return 0;
}