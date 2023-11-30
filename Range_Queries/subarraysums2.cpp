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
    int left, right;
    node(int lo, int hi): lo(lo), hi(hi), md((lo+hi)>>1) {}
};

vector<node> segTree;

void merge(int idx) {
    node &cur = segTree[idx];
    node &left = segTree[cur.left];
    node &right = segTree[cur.right];
    cur.pref = max(left.pref, left.sum + right.pref);
    cur.suff = max(right.suff, right.sum + left.suff);
    cur.sum = left.sum + right.sum;
    cur.val = max({left.val, right.val, left.suff + right.pref});
}

void build(int idx, vi &arr) {
    node &cur = segTree[idx];
    if(cur.lo == cur.hi) {
        cur.val = cur.sum = cur.pref = cur.suff = arr[cur.lo];
        return;
    }
    cur.left = sz(segTree);
    segTree.emplace_back(cur.lo, cur.md);
    cur.right = sz(segTree);
    segTree.emplace_back(cur.md+1, cur.hi);
    build(cur.left, arr);
    build(cur.right, arr);
    merge(idx);    
}

void init(int lo, int hi, vi& arr) {
    segTree = vector<node>();
    segTree.reserve(2*(hi-lo+1)-1);
    segTree.emplace_back(lo, hi);
    build(0, arr);
}

void update(int idx, int i, int v) {
    node &cur = segTree[idx];
    if(cur.lo == cur.hi)
        return void(cur.val = cur.sum = cur.pref = cur.suff = v);
    if(i <= cur.md)
        update(cur.left, i, v);
    else
        update(cur.right, i, v);
    merge(idx);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q; cin >> n >> q;
    vi arr(n);
    for(int &ai: arr) cin >> ai;

    init(0, n-1, arr);

    while(q--) {
        int i, v; cin >> i >> v;
        update(0, i-1, v);

        cout << max(0LL, segTree[0].val) << '\n';
    }

    return 0;
}