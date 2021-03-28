#include <iostream>
using namespace std;

/**
 * @param N : 入力
 * @param cur : 現在の値
 * @param use : 7, 5, 3のどれを使ったか
 * @param counter : 答え
 */
void func(long long N, long long cur, int use, long long &counter) {
    if (cur > N) { // ベースケース
        cout << cur << endl;
        return;
    } 
    if (use == 0b111) { ++counter; } // 答えを増やす

    // 7を付け加える
    func(N, cur * 10 + 7, use | 0b001, counter);

    // 5を付け加える
    func(N, cur * 10 + 5, use | 0b010, counter);

    // 3を付け加える
    func(N, cur * 10 + 3, use | 0b100, counter);
}

int main() {
    long long N;
    cin >> N;
    long long counter = 0;
    func(N, 0, 0, counter);
    cout << counter << endl;
}

