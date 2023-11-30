#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        if((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b))
            cout << "YES\n";
        else cout << "NO\n";
    }
}