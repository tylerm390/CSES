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
const int maxK = 100;
 
double dp[maxK+1][n][n];
double prob[n][n];
 
int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int k; cin >> k;
 
    rep(i, 0, n) rep(j, 0, n)
        prob[i][j] = 1;
 
    rep(si, 0, n) {
        rep(sj, 0, n) {
            memset(dp, 0, sizeof(dp));
            dp[0][si][sj] = 1;
            rep(iter, 0, k) {
                rep(i, 0, n) {
                    rep(j, 0, n) {
                        int cnt = 0;
                        rep(l, 0, 4) {
                            int ni = i + di[l], nj = j + dj[l];
                            if(ni < 0 || ni >= n || nj < 0 || nj >= n)
                                continue;
                            cnt++;
                        }
                        rep(l, 0, 4) {
                            int ni = i + di[l], nj = j + dj[l];
                            if(ni < 0 || ni >= n || nj < 0 || nj >= n)
                                continue;
                            dp[iter+1][ni][nj] += dp[iter][i][j] / cnt;
                        }
                    }
                }
            }
            rep(i, 0, n)
                rep(j, 0, n)
                    prob[i][j] *= (1-dp[k][i][j]);
        }
    }
 
    double res = 0;
    rep(i, 0, n)
        rep(j, 0, n)
            res += prob[i][j];
 
    cout << setprecision(6) << fixed << res << '\n';
 
    return 0;
}