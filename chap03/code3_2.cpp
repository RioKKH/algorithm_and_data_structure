#include <iostream>
#include <vector>
using namespace std;

/**
 * 特定の要素の存在する添字も取得する
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
    int found_id = -1; // 初期値は-1 などの有り得ない値にしておく
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            found_id = i; // 見つかったら添字を記録
            break; // ループを抜ける
        }
    }

    // 結果を出力する
    cout << found_id << endl;

    return 0;
}
