/**
 * 一般化した二分探索法の基本形
 */
#include <iostream>

using namespace std;

// xが条件を満たすかどうか
bool P(int x) {
    // ここに条件判定式が来る
}

// P(x) = trueとなる最小の整数xを返す
int binary_search()
{
    int left, right; // P(left) = false, P(right) = trueとなるように

    // 初期から終了まで変数leftは常にfalse側、変数rightは常にtrue側にいる。
    // 処理終了時、
    // rightはP(right) = trueを満たす最小の整数値
    // leftはP(left) = falseを満たす最大の整数値
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (P(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}
