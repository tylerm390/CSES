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

    int n, k; cin >> n >> k;
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    map<int, int> freq;
    int right = -1;
    ll ans = 0;
    rep(left, 0, n) {
        while(right < n-1 && (sz(freq) < k || freq.count(arr[right+1])))
            right++, freq[arr[right]]++;
        
        ans += right - left + 1;
        
        freq[arr[left]]--;
        if(!freq[arr[left]])
            freq.erase(arr[left]); 
    }

    cout << ans << '\n';

    return 0;
}