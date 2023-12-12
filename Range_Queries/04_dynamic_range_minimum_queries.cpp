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

const int inf = 2e9;

struct node {
    int lo, md, hi;
    int val;
    node *left, *right;
    node(int L, int R, vi &arr): lo(L), hi(R), md((L + R) / 2) {
        if(lo == hi) {
            val = arr[lo];
            return;
        }
        left = new node(lo, md, arr);
        right = new node(md+1, hi, arr);
        val = min(left->val, right->val);
    }
    void update(int i, int x) {
        if(lo == hi) return void(val = x);
        if(i <= md) left->update(i, x);
        else right->update(i, x);
        val = min(left->val, right->val);
    }
    int query(int L, int R) {
        if(R < lo || hi < L) return inf;
        if(L <= lo && hi <= R) return val;
        return min(left->query(L, R), right->query(L, R));
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q; cin >> n >> q;
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    node segTree(0, n-1, arr);

    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int i, x; cin >> i >> x;
            segTree.update(i-1, x);
        }
        else {
            int L, R; cin >> L >> R;
            cout << segTree.query(L-1, R-1) << '\n';
        }
    }

    return 0;
}