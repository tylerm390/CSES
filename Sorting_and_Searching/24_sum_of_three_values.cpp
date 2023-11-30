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

    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) -> bool {
        return arr[i] < arr[j];
    });
    
    rep(i, 0, n) {
        int left = i+1, right = n-1;
        while(left < right) {
            ll sum = arr[ord[i]] + (ll)arr[ord[left]] + (ll)arr[ord[right]]; 
            if(sum == x) {
                cout << ord[i]+1 << ' ' << ord[left]+1 << ' ' << ord[right]+1 << '\n';
                return 0;
            }

            if(sum < x)
                left++;
            else
                right--;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}