#include <iostream>

/**
 * 1からNまでの総和を計算する再帰関数
 * 再起呼び出しが泊まらない再帰関数
 * スタックオーバーフローでこける
 */

int func(int N) {
    // 再帰関数を呼び出したことを報告する
    std::cout << "func(" << N << ") を呼び出しました" << std::endl;

    if (N == 0) {
        return 0;
    }
    return N + func(N + 1);
}

int main() { func(5); }
