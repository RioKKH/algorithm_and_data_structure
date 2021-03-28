#include <iostream>
#include <vector>
using namespace std;

/**
 * 線形探索
 * 計算量 N個の値を順に調べていくのでO(N)
 */
int main(int argc, char const* argv[])
{
    // 入力を受け取る
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // 線形探索
    bool exist = false; // 初期値はfalseに
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            exist = true; // 見つかったらフラグを立てる
            // ここでbreakしても良いけれど、O(N)であることには変わりがない
        }
    }

    // 結果出力
    if (exist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
