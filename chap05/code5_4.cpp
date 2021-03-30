#include <iostream>
#include <vector>
using namespace std;

// choose minimum
template<class T> void chmin(T&a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // 十分大きな数値。ここでは2^60

int main(int argc, char const* argv[])
{
    // 入力
    int N;
    cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) { // 配る遷移方式なので、i=0から始まる
        cin >> h[i];
    }

    // 初期化 (最小化問題なので、INFに初期化)
    vector<long long> dp(N, INF);

    // 初期条件
    dp[0] = 0;

    // ループ
    // 配る遷移方式なので、i+1 or i+2の値を順次確定させていく
    for (int i = 0; i < N; ++i) {
        if (i + 1 < N) {
            chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if (i + 2 < N) {
            chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }

    // 答え
    cout << dp[N - 1] << endl;

    return 0;
}
