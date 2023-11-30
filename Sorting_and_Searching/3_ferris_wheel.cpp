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

    sort(all(arr));

    int cnt = n;
    int left = 0, right = n-1;
    while(left < right) {
        if(arr[left] + arr[right] <= x)
            cnt--, left++;
        right--;
    }

    cout << cnt << '\n';

    return 0;
}