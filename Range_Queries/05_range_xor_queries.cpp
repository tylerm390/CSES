#include <bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
 
int main() {
	cin.tie(0) -> sync_with_stdio(0);
	cin.exceptions(cin.failbit);
 
	int n, q; cin >> n >> q;
	vi a(n);
	for(int &ai: a) cin >> ai;
 
	vi xors(n+1);
	for(int i = 0; i < n; i++) {
		xors[i+1] = xors[i] ^ a[i];
	}
 
	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << (xors[b] ^ xors[a-1]) << '\n';
	}
 
	return 0;
}