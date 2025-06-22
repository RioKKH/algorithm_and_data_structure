/**
 * 入力: 重み付き有向グラフと始点
 * 出力: 始点から各頂点への最短距離
 * --> 最短経路そのものではなく、その長さ(重み)を求める
 * 特徴: 負の重みをもつ辺があっても正しく動作し、負閉路も検出できる
 *
 * test1.dat: 正の重みのみ
 * test2.dat: 負の重みあり、負閉路なし
 * test3.dat: 負閉路あり
 * test4.dat: 非連結グラフ
 * test5.dat: 複雑な例
 */
#include <iostream>
#include <vector>
using namespace std;

// デバッグ出力のON/OFF(簡単に切り替え可能)
const bool DEBUG = true;

// 無限大を表す値
// 十分大きな数値を用いる(ここでは2^60)
const long long INF = 1LL << 60;

// 辺を表す型、ここでは重みを表す型をlong long 型とする
struct Edge {
    int to;       // 隣接頂点番号
    long long w;  // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

// 重み付きグラフを表す型
using Graph = vector<vector<Edge>>;

// 緩和を実施する関数
template <class T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else
        return false;
}

// デバッグ用: 距離配列を表示
void printDist(const vector<long long>& dist, int iter = -1) {
    if (!DEBUG) return;

    if (iter >= 0) {
        cout << "反復 " << iter + 1 << ": ";
    } else {
        cout << "初期状態: ";
    }

    cout << "[";
    for (int i = 0; i < dist.size(); i++) {
        if (i > 0) cout << ", ";
        if (dist[i] < INF) {
            cout << dist[i];
        } else {
            cout << "∞";
        }
    }
    cout << "]" << endl;
}

int main() {
    // 頂点数、辺陬、始点
    int N, M, s;
    cin >> N >> M >> s;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    if (DEBUG) {
        cout << "=== ベルマン・フォード法開始 ===" << endl;
        cout << "頂点数: " << N << ", 辺数: " << M << ", 始点: " << s << endl;
    }

    // ベルマン・フォード法
    bool exist_negative_cycle = false;  // 負閉路を持つかどうか
    vector<long long> dist(N, INF);
    dist[s] = 0;

    printDist(dist);  // 初期状態を表示

    for (int iter = 0; iter < N; ++iter) {
        bool update = false;  // 更新が発生したかどうかを表すグラフ

        if (DEBUG) cout << "\n--- 反復" << iter + 1 << " ---" << endl;

        for (int v = 0; v < N; ++v) {
            // dist[v] == INF の時は頂点vからの緩和を行わない
            if (dist[v] == INF) continue;

            for (auto e : G[v]) {
                // 緩和処理を行い、更新されたらupdateをtrueにする
                long long old_dist = dist[e.to];
                if (chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                    if (DEBUG) {
                        cout << "  緩和: " << v << "→" << e.to << "  (重み"
                             << e.w << ") " << old_dist << "→" << dist[e.to]
                             << endl;
                    }
                }
            }
        }
        printDist(dist, iter);  // 各反復語の距離を表示

        // 更新が行われなかったら、すでに最短路が求められている
        if (!update) {
            if (DEBUG) cout << "更新無し - 早期終了" << endl;
            break;
        }

        // N回目の反復で更新が行われたならば、負閉路をもつ
        if (iter == N - 1 && update) {
            exist_negative_cycle = true;
            if (DEBUG) cout << "負閉路を検出!" << endl;
        }
    }

    if (DEBUG) cout << "\n=== 結果 ===" << endl;

    // 結果出力
    if (exist_negative_cycle)
        cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int v = 0; v < N; ++v) {
            if (dist[v] < INF)
                cout << dist[v] << endl;
            else
                cout << "INF" << endl;
        }
    }

    return 0;
}
