#include <iostream>
#include <vector>
#include <algorithm>

/**
 * N個の正の整数が与えられた時、N個すべての値が偶数であれば、
 * 2でわった値に置き換える、という処理を繰り返す。何回の操作
 * を行うことになるのかを求める。
 * 一番最初に奇数になる場合の処理の回数を求めれば良い
 */

const int INF = 20000000; // 十分に大きな数値に設定する

// Nが2で何回割れるか
int how_many_times(int N) {
    int exp = 0;
    while (N % 2 == 0) {
        N /= 2;
        ++exp;
    }
    return exp;
}

int main(int argc, char const* argv[])
{
    // 入力を受け取る
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) { std::cin >> A[i]; }

    int result = INF;
    // 線形探索
    for (auto a : A) {
        result = std::min(result, how_many_times(a));
    }

    // 結果出力
    std::cout << result << std::endl;

    return 0;
}





