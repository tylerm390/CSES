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

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};
string d = "ULDR";

const int inf = 1e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n+2, vector<char>(m+2, 'O'));
    int si = -1, sj = -1;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i+1][j+1];
            if(grid[i+1][j+1] == 'A')
                si = i+1, sj = j+1;
        }
    }
        
    vvi monstDists(n+2, vi(m+2, inf));
    
    {
        queue<pii> q;
        rep(i, 1, n+1) {
            rep(j, 1, m+1) {
                if(grid[i][j] == 'M') {
                    q.emplace(i, j);
                    monstDists[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            rep(k, 0, 4) {
                int ni = i + di[k], nj = j + dj[k];
                if(grid[ni][nj] != '.' || monstDists[ni][nj] != inf) continue;
                monstDists[ni][nj] = monstDists[i][j] + 1;
                q.emplace(ni, nj);
            }
        }
    }


    vvi dists(n+2, vi(m+2, inf));
    vvi dir(n+2, vi(m+2, -1));
    queue<pii> q;

    dists[si][sj] = 0;
    q.emplace(si, sj);

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        int nxtDist = dists[i][j] + 1;
        rep(k, 0, 4) {
            int ni = i + di[k], nj = j + dj[k];
            if(grid[ni][nj] == 'O') {
                dists[ni][nj] = nxtDist;
                dir[ni][nj] = k;
                continue;
            }
            if(grid[ni][nj] != '.' || nxtDist >= monstDists[ni][nj] || dists[ni][nj] != inf)
                continue;

            dists[ni][nj] = nxtDist;
            dir[ni][nj] = k;
            q.emplace(ni, nj);
        }
    }

    int bestDist = inf, bestI = -1, bestJ = -1;
    rep(i, 0, n+2) {
        rep(j, 0, m+2) {
            if(grid[i][j] != 'O') continue;
            if(dists[i][j] < bestDist) {
                bestDist = dists[i][j];
                bestI = i;
                bestJ = j;
            }
        }
    }

    if(bestDist == inf) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << dists[bestI][bestJ] - 1 << '\n';

    string dirs = "";
    int curI = bestI, curJ = bestJ;
    while(dir[curI][curJ] != -1) {
        int curDir = dir[curI][curJ];
        dirs += d[curDir];
        curI -= di[curDir];
        curJ -= dj[curDir];
    }

    reverse(all(dirs));
    cout << dirs.substr(0, dists[bestI][bestJ] - 1) << '\n';

    return 0;
}