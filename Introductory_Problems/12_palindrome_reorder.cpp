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

    string s; cin >> s;
    int n = sz(s);

    vi freq(26);

    for(char c: s) freq[c - 'A']++;

    int cntOdd = 0;
    rep(i, 0, 26) {
        cntOdd += freq[i] & 1;
    }

    if(cntOdd > 1 || (n & 1) == 0 && cntOdd == 1) {
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    string half = "";
    string middle = "";
    rep(i, 0, 26) {
        if(freq[i] & 1) {
            while(freq[i] > 0)
                middle += (char)(i + 'A'), freq[i]--;
            continue;
        }
        freq[i] >>= 1;
        while(freq[i] > 0)
            half += (char)(i + 'A'), freq[i]--;
    }

    string rev = half;
    reverse(all(rev));

    cout << half << middle << rev << '\n';

    return 0;
}