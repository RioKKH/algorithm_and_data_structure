/**
 * 二分探索法を用いて「ペアわを最適化する問題」に対する全探索解放を高速化する
 */

#include <iostream>
#include <vector>
#include <algorithm> // sort(), lower_bound()

using namespace std;
const int INF = 20'000'000; // 十分に大きな値に

int main()
{
    // 入力を受け取る
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) { cin >> a[i]; }
    for (int i = 0; i < N; ++i) { cin >> b[i]; }

    // 暫定最小値を格納する変数
    int min_value = INF;

    // bをソート
    // O(NlogN)
    sort(b.begin(), b.end());

    // bに無限大を表す値(INF)を追加しておく
    // これを行うことで、iter = b.end()となる可能性を除外する
    b.push_back(INF);

    // aを固定して解く
    for (int i = 0; i < N; ++i) {
        // bの中でK - a[1]以上の範囲での最小値を示すイテレータ
        auto iter = lower_bound(b.begin(), b.end(), K-a[i]);

        // イテレータの示す値を取り出す
        int val = *iter;

        // min_valueと比較する
        if (a[i] + val < min_value) {
            min_value = a[i] + val;
        }
    }
    cout << min_value << endl;
}
