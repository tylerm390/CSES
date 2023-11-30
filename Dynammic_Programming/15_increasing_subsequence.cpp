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
    int val = 0;
    node *left = nullptr, *right = nullptr;
    node(int lo, int hi): lo(lo), hi(hi), md((lo+hi)>>1) {}
    void check() {
        if(left) return;
        left = new node(lo, md);
        right = new node(md+1, hi);
    }
    void update(int idx, int v) {
        if(lo == hi) return void(val = v);
        check();
        if(idx <= md) left->update(idx, v);
        else right->update(idx, v);
        val = max(left->val, right->val);
    }
    int query(int idx) {
        if(idx < lo) return 0;
        if(idx >= hi) return val;
        check();
        return max(left->query(idx), right->query(idx));
    }
};

const int maxVal = 1e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;

    node dp(0, maxVal);
    rep(i, 0, n) {
        int v; cin >> v;
        int lis = dp.query(v-1);
        dp.update(v, lis+1);
    }

    cout << dp.query(maxVal) << '\n';

    return 0;
}