#include <iostream>

/**
 * 何度も同じ計算をする効率の悪いアルゴリズム
 */
int fibo(int N) {
    // 再帰関数を呼び出した事を報告する
    std::cout << "fibo(" << N << ") を呼び出しました" << std::endl;

    // ベースケース
    if (N == 0) {
        return 0;
    } else if (N == 1) {
        return 1;
    } else { // 再帰的に答えを求めて出力する
        int result = fibo(N - 1) + fibo(N - 2);
        std::cout << N << " 項目 = " << result << std::endl;

        return result;
    }
}

int main() {
    fibo(6);
}
