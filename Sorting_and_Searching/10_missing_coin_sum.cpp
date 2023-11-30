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
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    sort(all(arr));

    if(arr[0] != 1) {
        cout << 1 << '\n';
        return 0;
    }

    ll sum = 0;
    rep(i, 0, n) {
        sum += arr[i];
        if(i != n-1 && sum + 1 < arr[i+1])
            break;
    }

    cout << sum + 1 << '\n';

    return 0;
}