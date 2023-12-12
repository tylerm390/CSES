#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<ll>;
using vii = vector<pii>;
using vvi = vector<vi>;
 
const ll inf = 1'000'000'000'000'000'000;
 
struct node{
    node *left, *right;
    int lo, md, hi;
    ll val, lazy = 0;
    node(int lo_, int hi_, vi &v): lo(lo_), hi(hi_), md ((lo_+hi_) >> 1){
        if(lo == hi){
            val = v[lo];
            return;
        }
        left = new node(lo, md, v);
        right = new node(md+1, hi, v);
        val = min(left->val, right->val);
    }
    void prop(){
        if(lazy == 0) return;
        val += lazy;
        if(lo != hi){
            left -> lazy += lazy;
            right -> lazy += lazy;
        }
        lazy = 0;
    }
    void update(int l, int h, ll diff){
        if(l > hi || h < lo) return;
        if(l <= lo && hi <= h){
            lazy += diff;
            return;
        }
        prop();
        left -> update(l, h, diff);
        right -> update(l, h, diff);
        val = min(left->val, right->val);
    }
    ll query(int l, int h){
        if(l > hi || h < lo) return inf;
        prop();
        if(l <= lo && hi <= h)
            return val;
        return min(right->query(l, h), left->query(l, h));
    }
};
 
int main(){
    cin.tie() -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n, q; cin >> n >> q;
    vi arr(n);
    for(ll &i: arr)
        cin >> i;
    
    node seg(0, n-1, arr);
    for(int i = 0; i < q; i++){
        int o; cin >> o;
        if(o == 1){
            int a, b, u; cin >> a >> b >> u;
            seg.update(a-1, b-1, u);
        }
        else{
            int idx; cin >> idx;
            cout << seg.query(idx-1, idx-1) << endl;
        }
    }
 
    return 0;
}