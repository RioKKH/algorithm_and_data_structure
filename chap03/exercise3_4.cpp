#include <iostream>
#include <vector>
using namespace std;

const int INF = 20000000; // 十分に大きな値に設定する

/**
 * N個の整数が与えられたときに、2つ選んで差を取る。
 * 差の最大値を求めるO(N)のアルゴリズムを設計する
 */
int main(int argc, char const* argv[])
{
    // 入力を受け取る
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) { cin >> a[i]; }

    // 線形探索
    int min_value = INF;
    int max_value = -INF;
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_value) { min_value = a[i]; }
        if (a[i] > max_value) { max_value = a[i]; }
    }
    // 結果出力
    cout << max_value - min_value << endl;

    return 0;
}
