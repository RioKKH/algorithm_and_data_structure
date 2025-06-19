#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> depth;  // 便宜上グローバルに答えを格納する

// 根無し木を根付き木としたときの各頂点の深さを求める
// d: 頂点vの深さ (vが根の時はd = 0)
void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for (auto c : G[v]) {
        if (c == p) continue;  // 探索が親方向に逆流するのを防ぐ
        dfs(G, c, v, d + 1);   // dを1増やして子頂点へ
    }
}
