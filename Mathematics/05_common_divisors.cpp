#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
 
const int MAXVAL = 1e6;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n; cin >> n;
 
    vi freq(MAXVAL + 1);
    rep(i, 0, n) {
        int v; cin >> v;
        freq[v]++;
    }
 
    for(int d = MAXVAL; d >= 1; d--) {
        int cnt = 0;
        for(int v = 0; v <= MAXVAL; v += d)
            cnt += freq[v];
        
        if(cnt >= 2) {
            cout << d << '\n';
            break;
        }
    }
 
    return 0;
}