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

    auto solve = [&](int cur, int tar, int depth, auto &solve) -> void {
        if(depth == 1) {
            cout << cur << ' ' << tar << '\n';
            return;
        }

        int aux = 6 - cur - tar;
        solve(cur, aux, depth-1, solve);
        cout << cur << ' ' << tar << '\n';
        solve(aux, tar, depth-1, solve);
    };

    cout << (1 << n) - 1 << '\n';
    solve(1, 3, n, solve);

    return 0;
}