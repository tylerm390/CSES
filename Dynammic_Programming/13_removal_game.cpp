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

    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    auto solve = [&](int L, int R, auto &solve) -> ll {
        if(L > R) return 0;

        ll &cur = dp[L][R];
        if(cur != -1) return cur;

        ll left = arr[L] - solve(L+1, R, solve);
        ll right = arr[R] - solve(L, R-1, solve);

        return cur = max(left, right);
    };

    ll diff = solve(0, n-1, solve);
    ll tot = accumulate(all(arr), 0LL);

    cout << (diff + tot) / 2 << '\n';

    return 0;
}