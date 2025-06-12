#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// グラフGにおいて、頂点sを始点とした探索を行う
vector<int> search(const Graph &G, int s) {
    int N = (int)G.size();  // グラフの頂点数

    // グラフ探索の為のデータ構造
    vector<bool> seen(N, false);  // 全頂点を「未訪問」に初期化する
    // queue<int> todo;              // 空の状態 (深さ優先探索の場合 stack<int>)
    stack<int> todo;
    vector<int> visit_order;  // 訪問順序を記録する

    // 初期条件
    seen[s] = true;  // 始点sは探索済みとする
    todo.push(s);    // todoはsのみを含む状態となる

    // todoが空になるまで探索を行う
    while (!todo.empty()) {
        // todoから頂点を取り出す
        // int v = todo.front();  // queueの場合--> BFS
        int v = todo.top();  // stackの場合 --> DFS
        todo.pop();

        visit_order.push_back(v);  // 訪問した頂点を記録する

        // vから辿れる頂点を全て調べる
        for (int x : G[v]) {
            // 既に発見済みの頂点は探索しない
            if (seen[x]) continue;
            // 新たな頂点 x を探索済みとして todo に挿入する
            seen[x] = true;
            todo.push(x);
        }
    }
    return visit_order;
}

int main() {
    int N, M;  // N: 頂点の数, M: 辺の数
    cin >> N >> M;

    // グラフを初期化
    Graph G(N);

    // 辺の情報を読み込む (無向グラフとして処理)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int s;  // 開始頂点
    cin >> s;

    // グラフ探索を実行
    vector<int> visit_order = search(G, s);

    // 結果を出力
    cout << "訪問順序: ";
    for (int i = 0; i < visit_order.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << visit_order[i];
    }
    cout << endl;
    // cout << "探索結果:" << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << "頂点 " << i << ": " << (visit_order[i] ? "訪問済み" :
    //     "未訪問")
    //          << endl;
    // }
    // 訪問した長点数を出力
    // int count = 0;
    // for (bool v : visit_order) {
    //     if (v) count++;
    // }
    // cout << "訪問した頂点数:" << count << endl;
    cout << "訪問した頂点数:" << visit_order.size() << endl;
    return 0;
}
