#include <iostream>
#include <vector>

using namespace std;

// ここでは重みを表す型をlong long 型とする
struct Edge
{
    int to;     // 隣接頂点番号
    long long w;// 重み

    // 構造体のコンストラクターというのか初期化定義というのか
    Edge(int to, long long w) : to(to), w(w) {}
};

auto for_each = [] (auto first, auto last, auto f)
{
    for (auto iter = first; iter != last; ++iter) {
        f(*iter);
    }
};

auto print_value = [] (auto v, auto e)
{ 
    cout << v << ", " << e << std::endl; 
};

// 拡張点の隣接リストを、辺集合で表す
using Graph = vector<vector<Edge>>;

int main()
{
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;
    
    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    for_each(begin(G), end(G), print_value);
}
