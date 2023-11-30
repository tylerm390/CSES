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

const int n = 8;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    vector<string> grid(n);
    rep(i, 0, n) cin >> grid[i];

    vi rowUsed(n), colUsed(n), forDiagUsed(2*n-1), backDiagUsed(2*n-1);

    auto solve = [&](int i, int j, int placed, auto &solve) -> int {
        // Base Cases
        if(i == n) return placed == n;
        if(j == n) return solve(i+1, 0, placed, solve);

        // Don't place a queen
        int ans = solve(i, j+1, placed, solve);

        // Try placing a queen
        if(grid[i][j] == '.' && !rowUsed[i] && !colUsed[j] && !forDiagUsed[i+j] && !backDiagUsed[i-j+7]) {
            rowUsed[i] = colUsed[j] = forDiagUsed[i+j] = backDiagUsed[i-j+7] = true;
            ans += solve(i, j+1, placed+1, solve);
            rowUsed[i] = colUsed[j] = forDiagUsed[i+j] = backDiagUsed[i-j+7] = false;
        }

        return ans;
    };

    cout << solve(0, 0, 0, solve) << '\n';

    return 0;
}