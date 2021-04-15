#include <iostream>
#include <vector>

using namespace std;

template<class T> void chmin(T& a, T b)
{
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // 十分に大きい値とする (ここおでは2^60)

// 入力データと、メモ用のDPテーブル
int N;
vector<long long> h;
vector<long long> dp;

// メモ化再帰関数
long long rec(int i)
{
    // DPの値が更新されていたらそのままリターン
    if (dp[i] < INF) {
        return dp[i];
    }

    // ベースケース：足場０のコストは０
    if (i == 0) {
        return 0;
    }

    // 答えを表す変数をINFで初期化する
    long long res = INF;

    // 足場i - 1から来た場合
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

    // 足場i - 2からきた場合
    if (i > 1) {
        chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    }

    // 結果をメモ化しながら返す
    return dp[i] = res;
}

int main()
{
    // 入力受け取り
    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    // 初期化(最小化問題なのでINFに初期化)
    dp.assign(N, INF); // 要素がN個で値がINF

    // 答え
    cout << rec(N - 1) << endl;
}
