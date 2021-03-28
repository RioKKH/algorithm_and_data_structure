#include <iostream>
#include <vector>
using namespace std;

const int INF = 20000000; // 十分に大きな値に設定する

int main(int argc, char const* argv[])
{
    // 入力を受け取る
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) { cin >> a[i]; }
    for (int i = 0; i < N; ++i) { cin >> b[i]; }

    // 線形探索
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 和がK未満の場合は捨てる
            if (a[i] + b[j] < K) { continue; }

            // 和がK以上のものに絞られる
            
            // 最小値を更新
            if (a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
            }
        }
    }
    // 結果出力
    cout << min_value << endl;

    return 0;
}
