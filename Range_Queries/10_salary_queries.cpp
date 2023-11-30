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

const int inf = 1e9;

struct node {
    int lo, md, hi;
    int sum = 0;
    node *left, *right;
    node(int L, int R): lo(L), md((L + R) >> 1), hi(R) {
        if(lo == hi) return;
        left = new node(L, md);
        right = new node(md+1, R);
    }
    void update(int idx, int dif) {
        if(lo == hi) return void(sum += dif);
        if(idx <= md) left->update(idx, dif);
        else right->update(idx, dif);
        sum = left->sum + right->sum;
    }
    int query(int L, int R) {
        if(R < lo || hi < L) return 0;
        if(L <= lo && hi <= R) return sum;
        return left->query(L, R) + right->query(L, R);
    }
};

using query = tuple<char, int, int>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q; cin >> n >> q;
    
    vi vals;

    vi sals(n);
    rep(i, 0, n) {
        cin >> sals[i];
        vals.push_back(sals[i]);
    }

    vector<query> queries(q);
    for(auto &[type, a, b]: queries) {
        cin >> type >> a >> b;
        vals.push_back(b);
        if(type == '?') vals.push_back(a);
        else a--;
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    
    for(int &v: sals) 
        v = lower_bound(all(vals), v) - vals.begin();

    for(auto &[type, a, b]: queries) {
        b = lower_bound(all(vals), b) - vals.begin();
        if(type == '?')
            a = lower_bound(all(vals), a) - vals.begin();
    }

    node segTree(0, sz(vals)-1);
    for(int v: sals)
        segTree.update(v, 1);
    
    for(auto [type, a, b]: queries) {
        if(type == '!') {
            segTree.update(sals[a], -1);
            segTree.update(b, 1);
            sals[a] = b;
        }
        else cout << segTree.query(a, b) << '\n';
    }

    return 0;
}