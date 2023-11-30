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

    int n, m; cin >> n >> m;
    vi arr(n);
    for(int &ai: arr) cin >> ai, ai--;

    vi idx(n);
    rep(i, 0, n)
        idx[arr[i]] = i;

    int cnt = 1;
    rep(i, 1, n)
        cnt += idx[i-1] > idx[i];

    auto update = [&](int i, int j) -> void {
        if(i == j) return;
        if(i > j) swap(i, j);

        if(arr[i] < n-1 && i < idx[arr[i]+1] && j > idx[arr[i]+1]) cnt++;
        if(arr[i] < n-1 && i > idx[arr[i]+1] && j < idx[arr[i]+1]) cnt--;

        if(arr[i] > 0 && idx[arr[i]-1] < i && idx[arr[i]-1] > j) cnt++;
        if(arr[i] > 0 && idx[arr[i]-1] > i && idx[arr[i]-1] < j) cnt--;


        if(arr[j] < n-1 && j < idx[arr[j]+1] && i > idx[arr[j]+1]) cnt++;
        if(arr[j] < n-1 && j > idx[arr[j]+1] && i < idx[arr[j]+1]) cnt--;

        if(arr[j] > 0 && idx[arr[j]-1] < j && idx[arr[j]-1] > i) cnt++;
        if(arr[j] > 0 && idx[arr[j]-1] > j && idx[arr[j]-1] < i) cnt--;

        if(abs(arr[i] - arr[j]) == 1) {
            if(arr[i] < arr[j]) cnt++;
            else cnt--;
        }

        idx[arr[i]] = j;
        idx[arr[j]] = i;
        swap(arr[i], arr[j]);
    };

    while(m--) {
        int i, j; cin >> i >> j;
        update(i-1, j-1);
        cout << cnt << '\n';
    }

    return 0;
}