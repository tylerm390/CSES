#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

struct node {
    int lo, md, hi;
    int val, sum, pref, suff;
    node *left, *right;
    node(int L, int R, vi &arr): lo(L), md((L+R)>>1), hi(R) {
        if(lo == hi) {
            val = sum = pref = suff = arr[lo];
            return;
        }
        left = new node(lo, md, arr);
        right = new node(md+1, hi, arr);
        merge();
    }
    void merge() {
        pref = max(left->pref, left->sum + right->pref);
        suff = max(right->suff, right->sum + left->suff);
        sum = left->sum + right->sum;
        val = max({left->val, right->val, left->suff + right->pref});
    }
    void update(int idx, int v) {
        if(lo == hi) return void(pref = suff = sum = val = v);
        if(idx <= md) left->update(idx, v);
        else right->update(idx, v);
        merge();
    }  
    int query() {
        return val;
    }
};

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q; cin >> n >> q;
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    node segTree(0, n-1, arr);

    while(q--) {
        int idx, v; cin >> idx >> v;
        segTree.update(idx-1, v);
        cout << max(0LL, segTree.query()) << '\n';
    }

    return 0;
}