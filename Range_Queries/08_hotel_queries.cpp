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

struct node {
    int lo, md, hi;
    int maxCap;
    node *left, *right;
    node(int L, int R, vi &arr): lo(L), md((L+R)>>1), hi(R) {
        if(L == R) {
            maxCap = arr[L];
            return;
        }
        left = new node(lo, md, arr);
        right = new node(md+1, hi, arr);
        maxCap = max(left->maxCap, right->maxCap);
    }
    void update(int idx, int val) {
        if(lo == hi) return void(maxCap -= val);
        if(idx <= md) left->update(idx, val);
        else right->update(idx, val);
        maxCap = max(left->maxCap, right->maxCap);
    }
    int find(int val) {
        if(maxCap < val) return -1;
        if(lo == hi) return lo;
        if(left->maxCap >= val) return left->find(val);
        return right->find(val);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m; cin >> n >> m;

    vi arr(n);
    for(int &ai: arr) cin >> ai;

    node segTree(0, n-1, arr);
    while(m--) {
        int val; cin >> val;
        int idx = segTree.find(val);
        cout << idx + 1 << ' ';
        if(idx != -1) segTree.update(idx, val);
    }
    cout << '\n';

    return 0;
}