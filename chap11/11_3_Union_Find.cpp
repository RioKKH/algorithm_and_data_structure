#include <iostream>
#include <vector>

using namespace std;

// Union-Find
class UnionFind
{
    vector<int> par, siz;

    // constructor
    UnionFind(int n) : par(n, -1), siz(n, 1) {}


    // 根を求める
    int root(int x)
    {
        if (par[x] == -1) { return x; } // xが根の場合はxを返す
        else { return par[x] = root(par[x]);
        }
