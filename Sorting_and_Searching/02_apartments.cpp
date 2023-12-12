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

    int n, m, k; cin >> n >> m >> k;
    vi a(n), b(m);
    for(int &ai: a) cin >> ai;
    for(int &bi: b) cin >> bi;

    sort(all(a));
    sort(all(b));

    int ptr = 0, cnt = 0;
    rep(i, 0, m) {
        if(ptr >= n) break;
        while(ptr <= n-1 && a[ptr] < b[i] - k) ptr++;
        if(ptr < n && a[ptr] <= b[i] + k) cnt++, ptr++;
    }

    cout << cnt << '\n';

    return 0;
}