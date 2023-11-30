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

const int n = 7;

bool seen[n][n];
string path;
int len;

bool inBounds(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

int solve(int i, int j, int idx) {
    if(idx == len || (i == n-1 && j == 0))
        return (idx == len && i == n-1 && j == 0);
    

    // Check if we hit a split point
    if((!inBounds(i+1, j) || seen[i+1][j]) && (!inBounds(i-1, j) || seen[i-1][j]))
        if(inBounds(i, j+1) && !seen[i][j+1] && inBounds(i, j-1) && !seen[i][j-1])
            return 0;
    
    if((!inBounds(i, j+1) || seen[i][j+1]) && (!inBounds(i, j-1) || seen[i][j-1]))
        if(inBounds(i+1, j) && !seen[i+1][j] && inBounds(i-1, j) && !seen[i-1][j])
            return 0;

    seen[i][j] = true;

    int ans = 0;
    
    // Try moving
    if(path[idx] == '?' || path[idx] == 'D')
        if(inBounds(i+1, j) && !seen[i+1][j])
            ans += solve(i+1, j, idx+1);

    if(path[idx] == '?' || path[idx] == 'U')
        if(inBounds(i-1, j) && !seen[i-1][j])
            ans += solve(i-1, j, idx+1);

    if(path[idx] == '?' || path[idx] == 'R')
        if(inBounds(i, j+1) && !seen[i][j+1])
            ans += solve(i, j+1, idx+1);

    if(path[idx] == '?' || path[idx] == 'L')
        if(inBounds(i, j-1) && !seen[i][j-1])
            ans += solve(i, j-1, idx+1);

    seen[i][j] = false;

    return ans;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> path;
    len = sz(path);
    cout << solve(0, 0, 0) << '\n';

    return 0;
}