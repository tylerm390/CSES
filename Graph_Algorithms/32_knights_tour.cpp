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

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

using opt = tuple<int, int, int>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int sx, sy; cin >> sx >> sy; sx--, sy--;

    vvi res(n, vi(n, -1));

    auto degree = [&](int x, int y) -> int {
        int cnt = 0;
        rep(i, 0, n) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            cnt += res[ny][nx] == -1;
        }
        return cnt;
    };

    auto solve = [&](int x, int y, int cur, auto &solve) -> bool {
        res[y][x] = cur;
        if(cur == n*n) return true;

        vector<opt> opts;
        rep(i, 0, n) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            opts.emplace_back(degree(nx, ny), nx, ny); 
        }

        sort(all(opts));
        for(auto [_, nx, ny]: opts) {
            if(res[ny][nx] != -1) continue;
            if(solve(nx, ny, cur+1, solve))
                return true;
        }

        res[y][x] = -1;
        return false;
    };

    assert(solve(sx, sy, 1, solve));

    rep(i, 0, n) {
        rep(j, 0, n)    
            cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}