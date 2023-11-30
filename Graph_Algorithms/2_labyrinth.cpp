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

const int inf = 1e9;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};
string d = "ULDR";

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(string &s: grid)
        cin >> s;

    int si = -1, sj = -1;
    int ei = -1, ej = -1;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(grid[i][j] == 'A')
                si = i, sj = j;
            if(grid[i][j] == 'B')
                ei = i, ej = j;
        }
    }

    vvi dist(n, vi(m, inf));
    vvi dir(n, vi(m, -1));

    queue<pii> q;
    
    dist[si][sj] = 0;
    q.emplace(si, sj);

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        rep(k, 0, 4) {
            int ni = i + di[k], nj = j + dj[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;
            if(grid[ni][nj] == '#' || dist[ni][nj] != inf)
                continue;

            dist[ni][nj] = dist[i][j] + 1;
            dir[ni][nj] = k;
            q.emplace(ni, nj);
        }
    }

    if(dist[ei][ej] == inf) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    cout << dist[ei][ej] << '\n';

    string dirs = "";
    int i = ei, j = ej;
    while(i != si || j != sj) {
        int curDir = dir[i][j];
        dirs += d[curDir];
        i -= di[curDir];
        j -= dj[curDir];
    }

    reverse(all(dirs));

    cout << dirs << '\n';

    return 0;
}