#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;  // vを訪問済みにする

    // vからいける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;  // next_vが探索済みならば探索しない
        dfs(G, next_v);              // 再帰的に探索する
    }
}

int main() {
    // 頂点数と辺数 s と t
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    // グラフ入力受け取り
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 頂点sをスタートした探索
    seen.assign(N, false);  // 全頂点を未訪問に初期化
    dfs(G, s);

    // tにたどり着けるかどうか
    if (seen[t]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
