/**
 * @file 13_9_DFS_for_rooted_tree_with_depth_and_size_test.cpp
 *
 * @note テストにはtest4.datを用いる
 */

#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 木上の探索
vector<int> depth;
vector<int> subtree_size;
vector<int> visit_order;  // 訪問順を記録する

void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    visit_order.push_back(v);  // 訪問順序を記録する

    cout << "訪問: 頂点" << v << " (深さ " << d << ")" << endl;

    for (auto c : G[v]) {
        if (c == p) continue;  // 探索が親方向へ逆流するのを防ぐ
        dfs(G, c, v, d + 1);
    }

    // 帰りがけ時に、部分木サイズを求める
    subtree_size[v] = 1;  // 自分自身
    for (auto c : G[v]) {
        if (c == p) continue;

        // 子頂点を根とする部分木のサイズを加算する
        subtree_size[v] += subtree_size[c];
    }
    cout << "帰りがけ: 頂点" << v << "の部分木サイズ = " << subtree_size[v]
         << endl;
}

int main() {
    // 頂点数 (木なので辺陬は N - 1 で確定)
    int N;
    cin >> N;

    // グラフ入力受け取り
    Graph G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    int root = 0;  // 仮に頂点0を根とする
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    visit_order.clear();

    cout << "=== DFS開始 (根: " << root << ") ===" << endl;
    dfs(G, root);
    cout << "=== DFS終了 ===" << "\n\n";

    // 訪問順序を出力する
    cout << "DFS訪問順序: ";
    for (int i = 0; i < visit_order.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << visit_order[i];
    }
    cout << "\n\n";

    // 結果
    cout << "=== 最終結果 ===" << endl;
    for (int v = 0; v < N; ++v) {
        cout << "頂点" << v << ": depth = " << depth[v]
             << ", subtree_size = " << subtree_size[v] << endl;
    }

    return 0;
}
