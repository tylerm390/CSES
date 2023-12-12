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

    ll n; cin >> n;
    ll prev;
    do {
        cout << n << ' ';
        prev = n;
        if(n % 2)
            n = 3*n + 1;
        else
            n /= 2;
    } while(prev != 1);
    
    cout << '\n';

    return 0;
}