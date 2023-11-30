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

struct DS {
    vi p;
    DS(int n): p(n, -1) {}
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    int nWalls = 0;
    for(auto &s: grid) {
        cin >> s;
        for(char c: s)
            nWalls += c == '#';
    }

    int nRooms = n*m - nWalls;

    DS ds(n*m);
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(grid[i][j] == '#')
                continue;
            rep(k, 0, 4) {
                int ni = i + di[k], nj = j + dj[k];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m)
                    continue;
                if(grid[ni][nj] == '.' && ds.join(i*m + j, ni*m + nj))
                    nRooms--;
            }
        }
    }

    cout << nRooms << '\n';

    return 0;
}