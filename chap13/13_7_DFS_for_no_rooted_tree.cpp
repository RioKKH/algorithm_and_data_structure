#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// 根無し木の走査の実装の基本形
// 木上の探索
// v: 現在探索中の頂点
// p: vの親 (vが根の時は p = -1)
void dfs(const Graph &G, int v, int p = -1) {
    for (auto c : G[v]) {
        if (c == p) continue;  // 探索が親方向へ逆流するのを防ぐ

        // cはvの各子頂点を動く。この時cの親はvとなる。
        dfs(G, c, v);
    }
}
