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

    string s; cin >> s;
    int n = sz(s);

    int ans = 0;
    rep(i, 0, n) {
        int j = i+1;
        while(j < n && s[j] == s[i])
            j++;
        ans = max(ans, j - i);
        i = j-1;
    }

    cout << ans << '\n';

    return 0;
}