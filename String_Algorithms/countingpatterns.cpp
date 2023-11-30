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

const int ABSIZE = 26;

struct node {
    int nxt[ABSIZE];
    vi ids = {};
    int prv = -1, link = -1;
    char c;
    int linkMemo[ABSIZE];

    node(int prv = -1, char c = '$'): prv(prv), c(c) {
        fill(all(nxt), -1);
        fill(all(linkMemo), -1);
    }
};

vector<node> trie(1);

void addWord(string &s, int id) {
    int cur = 0;
    for(char c: s) {
        int idx = c - 'a';
        if(trie[cur].nxt[idx] == -1) {
            trie[cur].nxt[idx] = sz(trie);
            trie.emplace_back(cur, c);
        }
        cur = trie[cur].nxt[idx];
    }
    trie[cur].ids.push_back(id);
}

int getLink(int cur);

int calc(int cur, char c) {
    int idx = c - 'a';
    auto &ret = trie[cur].linkMemo[idx];
    if(ret != -1) return ret;
    if(trie[cur].nxt[idx] != -1)
        return ret = trie[cur].nxt[idx];
    return ret = cur == 0 ? 0 : calc(getLink(cur), c);
}

int getLink(int cur) {
    auto &ret = trie[cur].link;
    if(ret != -1) return ret;
    if(cur == 0 || trie[cur].prv == 0) return ret = 0;
    return ret = calc(getLink(trie[cur].prv), trie[cur].c);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    string s; cin >> s;
    int n; cin >> n;
    rep(i, 0, n) {
        string pat; cin >> pat;
        addWord(pat, i);
    }

    int cur = 0;
    vi seen(sz(trie));
    for(char c: s) {
        int idx = c - 'a';
        while(cur != 0 && trie[cur].nxt[idx] == -1)
            cur = getLink(cur);
        if(trie[cur].nxt[idx] != -1)
            cur = trie[cur].nxt[idx];

        seen[cur]++;
    }

    vvi adj(sz(trie));
    rep(i, 1, sz(trie)) {
        adj[getLink(i)].push_back(i);
    }

    vi reachable(n);
    auto dfs = [&](int cur, auto &dfs) -> int {
        int cnt = seen[cur];
        for(int nxt: adj[cur]) {
            cnt += dfs(nxt, dfs);
        }
        
        for(int id: trie[cur].ids)
            reachable[id] += cnt;
        
        return cnt;
    };

    dfs(0, dfs);

    rep(i, 0, n)
        cout << reachable[i] << '\n';

    return 0;
}