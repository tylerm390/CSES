#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int solve(int n, int k) {
    if(n == 1) return 1;
    if(k <= (n+1)/2) return (n%2) ? 2*k % n : 2*k;
    if(n%2) return 2*solve(n/2, k - (n+1)/2) + 1;
    return 2*solve(n/2, k - n/2) - 1;
}
 
int main() {
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
}