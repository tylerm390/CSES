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

    int n; cin >> n;
    vii events;
    rep(i, 0, n) {
        int s, e; cin >> s >> e;
        events.emplace_back(s, ~i);
        events.emplace_back(e, i);
    }

    sort(all(events));

    vi roomId(n, -1);
    int curRoom = 1;
    queue<int> available;

    for(auto [_, idx]: events) {
        if(idx < 0) {
            idx = ~idx;
            if(available.empty()) {
                roomId[idx] = curRoom++;
            }
            else {
                roomId[idx] = available.front();
                available.pop();
            }
        }
        else 
            available.push(roomId[idx]);
    }

    cout << curRoom-1 << '\n';
    for(int i: roomId)
        cout << i << ' ';
    cout << '\n';

    return 0;
}