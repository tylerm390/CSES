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

    if(n % 4 == 1 || n % 4 == 2) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES\n";

    vi set1, set2;

    int init;

    if(n % 4 == 0)
        init = 1;    
    else {
        set1 = {1, 2};
        set2 = {3};
        init = 4;
    }

    for(int i = init; i <= n; i += 4) {
        set1.push_back(i);
        set1.push_back(i + 3);
        set2.push_back(i + 1);
        set2.push_back(i + 2);
    }

    cout << sz(set1) << '\n';
    for(int i: set1) cout << i << ' ';
    cout << '\n';

    cout << sz(set2) << '\n';
    for(int i: set2) cout << i << ' ';
    cout << '\n';

    return 0;
}