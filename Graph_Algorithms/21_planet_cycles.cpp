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

struct DSU {
    vi e;
    DSU(int n): e(n, -1) {}
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(e[x] < e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

int n;

vvi comps;
vi compId;

void decompose(vi &f) {
    DSU dsu(n);
    rep(i, 0, n)
        dsu.join(i, f[i]);
    
    comps = vvi(n);
    compId = vi(n);
    rep(i, 0, n) {
        comps[dsu.find(i)].push_back(i);
        compId[i] = dsu.find(i);
    }
}

vi cycleSizes;

vi cycleIds;
vector<bool> inCycle;

void findCycles(vi &f) {
    vi deg(n);
    rep(i, 0, n)
        deg[f[i]]++;
    
    queue<int> q;
    rep(i, 0, n)
        if(deg[i] == 0)
            q.push(i);
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        inCycle[cur] = false;
        deg[f[cur]]--;
        if(deg[f[cur]] == 0)
            q.push(f[cur]);
    }
}

void enumerateCycle(int start, int id, vi &f) {
    int cur = start;
    int cnt = 0;
    do {
        cycleIds[cur] = cnt++;
        cur = f[cur];
    } while(cur != start);
    cycleSizes[id] = cnt;
}

vi cycleDist;

void getCycleDist(int id, vi &f) {
    auto dp = [&](int cur, auto &dp) -> int {
        if(inCycle[cur]) return cycleDist[cur] = 0;
        if(cycleDist[cur] != -1) return cycleDist[cur];
        cycleDist[cur] = dp(f[cur], dp) + 1;
        return cycleDist[cur];
    };

    for(int i: comps[id])
        dp(i, dp);
}


int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    vi f(n);
    rep(i, 0, n)
        cin >> f[i], f[i]--;

    decompose(f);

    cycleIds = vi(n, -1);
    cycleSizes = vi(n);
    inCycle = vector<bool>(n, true);
    findCycles(f);

    rep(i, 0, n) {
        if(comps.empty()) continue;
        for(int j: comps[i]) {
            if(inCycle[j]) {
                enumerateCycle(j, i, f);
                break;
            }
        }
    }

    cycleDist = vi(n, -1);
    rep(i, 0, n)
        if(!comps.empty())
            getCycleDist(i, f);

    rep(i, 0, n)
        cout << cycleDist[i] + cycleSizes[compId[i]] << ' ';
    cout << '\n';

    return 0;
}