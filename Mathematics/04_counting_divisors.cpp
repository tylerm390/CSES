#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n; cin >> n;   
    while(n--) {
        int x; cin >> x;
        int cnt = 0;
        for(int i = 1; i*i <= x; i++)
            if(x % i == 0)
                cnt += 1 + (i*i != x);
        cout << cnt << endl;
    }
 
    return 0;
}