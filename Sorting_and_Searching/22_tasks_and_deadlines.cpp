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
    vii tasks(n);
    for(auto &[a, d]: tasks) cin >> a >> d;

    sort(all(tasks));

    ll curTime = 0;
    ll reward = 0;
    for(auto [a, d]: tasks) 
        curTime += a, reward += d - curTime;
    
    cout << reward << '\n';

    return 0;
}