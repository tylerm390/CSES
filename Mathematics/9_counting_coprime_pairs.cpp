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
 
const ll mod = 1e9+7;
const ll maxVal = 1e6;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    vi mu(maxVal+1);
    mu[1] = 1;
    rep(i, 1, maxVal+1)
        for(int j = 2*i; j <= maxVal; j += i)
            mu[j] -= mu[i];
        
    int n; cin >> n;
    vi freq(maxVal+1);
    rep(i, 0, n) {
        int v; cin >> v;
        freq[v]++;
    }
 
    rep(i, 1, maxVal + 1)
        for(int j = 2*i; j <= maxVal; j += i)
            freq[i] += freq[j];
 
    ll cnt = 0;
    rep(i, 0, maxVal+1)
        cnt += mu[i] * freq[i] * (ll) (freq[i]-1) / 2;
    
    cout << cnt << '\n';
 
    return 0;
}