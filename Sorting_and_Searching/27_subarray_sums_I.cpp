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

    int n, x; cin >> n >> x;
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    int cnt = 0;
    ll sum = 0;
    int right = 0;
    rep(left, 0, n) {
        while(right < n && sum < x)
            sum += arr[right], right++;
        cnt += sum == x;
        sum -= arr[left];
    }

    cout << cnt << '\n';

    return 0;
}