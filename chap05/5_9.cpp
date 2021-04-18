#include <iostream>
#include <vector>

using namespace std;

template<class T> void chmin(T& a, T b)
{
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // 十分に大きな数 (2^60)

int main()
{
    // 入力
    int N;
    cin >> N;
    vector<vector<long long>> c(N + 1, vector<long long>(N + 1));
    // 重み係数を読み取り。各区間の重み。
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            cin >> c[i][j];
        }
    }

    // DPテーブル定義
    vector<long long> dp(N+1, INF);

    // DP初期条件
    dp[0] = 0;

    // DPループ
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            chmin(dp[i], dp[j] + c[i][j]);
        }
    }

    // 答えの出力
    cout << dp[N] << endl;
}
