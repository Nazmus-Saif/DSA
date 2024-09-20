#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int N, M;
vector<vector<int>> adj;
vector<int> color;

// Returns true if there is a cycle of odd length starting from node u
bool dfs(int u, int p, int c) {
    color[u] = c;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (color[v] == c) return true;
        if (color[v] == 0 && dfs(v, u, 3 - c)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    adj.resize(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color.resize(N);
    for (int i = 0; i < N; ++i) {
        if (color[i] == 0 && dfs(i, -1, 1)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}