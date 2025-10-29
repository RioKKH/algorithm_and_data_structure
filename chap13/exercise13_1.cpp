/// @file exercise13_1.cpp
/// @brief グラフの連結成分を深さ優先探索(DFS)を用いて探索するプログラム
///
/// 無向グラフの連結成分数を計算する。
/// 各未訪問の頂点からDFSを開始し、到達可能な全ての頂点を訪問することで、
/// 連結成分を特定する。

#include <iostream>
#include <vector>

using namespace std;

/// グラフを表す型
/// Graph[v] は頂点vに隣接する頂点のリストを保持する
using Graph = vector<vector<int>>;

/// 各頂点の訪問状態を記録するグローバル変数
/// seen[v]がtrueの場合、頂点vは訪問済み
vector<bool> seen;

/**
 * @brief 深さ優先探索 (DFS)を実行し、頂点vから到達可能な全頂点を訪問する
 *
 * @param G 探索対象のグラフ(隣接リスト形式)
 * @param v 探索を開始する頂点
 *
 * @note この関数は再帰的に呼び出され、グローバル変数seenを更新する
 * @note 時間計算量: O(V + E) ここではVは頂点数、Eは辺数
 *
 * @par アルゴリズム
 * 1. 現在の頂点vを訪問済みのマークする
 * 2. vに隣接する各頂点について:
 *    - 未訪問であれば再帰的にDFSを実行する
 */
void dfs(const Graph &G, int v) {
    // 頂点 v を訪問済みにする
    seen[v] = true;

    // 頂点 v に隣接する各頂点を探索する
    for (auto next_v : G[v]) {
        // 探索済みの頂点は探索しない
        if (seen[next_v]) continue;

        // 再帰的に探索をする
        dfs(G, next_v);
    }
}

/**
 * @brief メイン関数: 標準入力からグラフを読み込み、連結成分数を計算する
 *
 * @return プログラムの終了コード (0: 正常終了)
 *
 * @par 入力形式:
 * @code
 *   N M
 *   a_1 b_1
 *   a_2 b_2
 *   ...
 *   a_M b_M
 * @endcode
 * - N: 頂点数 (0 <= N <= 100000)
 * - M: 辺数   (0 <= M <= 100000)
 * - a_i, b_i: 辺の両端の頂点 (0 <= a_i, b_i <= N)
 *
 * @par アルゴリズムの概要:
 * 1. グラフを隣接リストとして構築
 * 2. 全頂点を未訪問に初期化
 * 3. 各未訪問頂点からDFSを開始 (新しい連結成分の発見)
 * 4. 連結成分の総数を出力
 *
 */
int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受け取り
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);  // 辺a -> b
        G[b].push_back(a);  // 辺b -> a (無向グラフなので双方向)
    }

    // 全頂点が探索済みになるまで DFS
    int result = 0;
    seen.assign(N, false);  // 全頂点を未訪問に初期化
    for (int v = 0; v < N; ++v) {
        // 探索済みの連結成分はスキップする
        if (seen[v]) continue;

        // 頂点 v を始点としたDFS
        dfs(G, v);

        // 連結成分数が増える
        ++result;
    }
    cout << result << endl;
}
