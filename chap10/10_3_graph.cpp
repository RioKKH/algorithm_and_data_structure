#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

int main()
{
    // 頂点数と変数
    int N, M;
    cin >> N >> M;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);

        // 無向グラフの場合には以下を追加する
        // G[b].push_back(a);
    }
}
