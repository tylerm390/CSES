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
    sort(all(s));

    vector<string> res;

    do { res.push_back(s); } while(next_permutation(all(s)));

    sort(all(res));
    res.erase(unique(all(res)), res.end());

    cout << sz(res) << '\n';
    for(string s: res)
        cout << s << '\n';

    return 0;
}