#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/// グラフを表す型
using Graph = vector<vector<int>>;

/// 頂点sを始点としたBFS
vector<int> dist;  // BFSに用いる距離を記録するための配列

void bfs(const Graph &G, int s) {
    queue<int> que;

    // 初期条件
    dist[s] = 0;
    que.push(s);

    // キューが空になるまで探索
    while (!que.empty()) {
        // キューから先頭要素を取り出す
        int v = que.front();
        que.pop();

        // 頂点vに隣接する各頂点を探索する
        for (auto next_v : G[v]) {
            // 探索済みの頂点は探索しない
            if (dist[next_v] != -1) continue;

            // 新たな頂点をキューに追加する
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}

int main() {
    // 頂点数を辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受け取り
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(b);
    }

    // 配列dist全体を-1に初期化する
    // -1は「未訪問」を意味する
    dist.assign(N, -1);

    // 各頂点からのBFS
    int result = 0;
    for (int v = 0; v < N; ++v) {
        // 探索済みの連結成分はスキップする
        if (dist[v] != -1) continue;

        // 頂点vを始点としたDFS
        bfs(G, v);

        // 連結成分数が増える
        ++result;
    }
    cout << result << endl;
}
