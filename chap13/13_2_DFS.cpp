#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
vector<int> visit_order;  // 訪問順序を記録する
void dfs(const Graph &G, int v) {
    seen[v] = true;            // vを訪問済みにする
    visit_order.push_back(v);  // 訪問順序を追加する
    // vからいける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;  // next_vが探索済みならば探索しない
        dfs(G, next_v);              // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受け取り (ここでは有向グラフを想定)
    // test2.dat
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(N, false);  // 初期状態では全頂点が未訪問
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue;  // 既に訪問済みなら探索しない
        dfs(G, v);
    }

    // 訪問順序を出力
    cout << "DFS訪問順序: ";
    for (int i = 0; i < visit_order.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << visit_order[i];
    }
    cout << endl;

    cout << "訪問した頂点数: " << visit_order.size() << endl;

    return 0;
}
