#include <iostream>
#include <vector>
using namespace std;

// Union-Find
struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, 1), siz(n, 1) {}

    // 根を求める
    // 経路圧縮の工夫ありの場合
    int root(int x) {
        if (par[x] == -1)
            return x;  // xが根の場合はxを直接返す
        else
            return par[x] = root(par[x]);  // xの親par[x]を根に設定する
    }
    // xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool issame(int x, int y) { return root(x) == root(y); }

    // xを含むグループとyを含むグループとを併合する
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x) { return siz[root(x)]; }
};

int main() {
    int N, M;
    cin >> N >> M;

    // Union-Findを要素数Ｎで初期化
    UnionFind uf(N);

    // 各辺に対する処理
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);  // aを含むグループとbを含むグループを併合する
    }

    // 集計
    int res = 0;
    for (int x = 0; x < N; ++x) {
        if (uf.root(x) == x) ++res;
    }
    cout << res << endl;
}
