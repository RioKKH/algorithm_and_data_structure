#include <iostream>
#include <vector>

using namespace std;

template<class T> void chmax(T& a, T b)
{
    if (a < b) {
        a = b;
    }
}

int main()
{
    // 入力
    int N;
    long long W;
    cin >> N >> W;
    vector<long long> weight(N);
    vector<long long> value(N);
    for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
    }

    // DPテーブル定義
    // ２次元のテーブルを生成
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    // DPループ
    for (int i = 0; i < N; ++i) {
        for (int w = 0; w <= W; ++w) {
            // i番目のしなものを選ぶ場合
            if (w - weight[i] >= 0) {
                // 選んだあとに(i + 1, w)の状態になるならば、選ぶ前は
                // (i, w - weight[i])の状態であり、その状態にvalue[i]が
                // 加わるので、
                chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
            }

            // i番目の品物を選ばない場合
            // 選ばないならば、重さも価値も特に変化しないので
            chmax(dp[i + 1][w], dp[i][w]);
        }
    }

    // 最適値の出力
    cout << dp[N][W] << endl;
}

