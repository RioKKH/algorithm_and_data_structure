/**
 *高橋君は最近、射撃にハマっている。 
 * 高橋君は N 個の風船すべてを射撃で割り、得られる得点をできるだけ小さくする
 * 競技に参加している。
 * 風船には 1から N までの番号が付けられていて、風船 i(1≦i≦N) は競技開始時に
 * 高度 Hi のところにあり、1 秒経過するにつれて高度が Si だけ増加する。 
 * 高橋君は競技開始時に 1個風船を割ることができ、そこから 1 秒ごとに 1 個の
 * 風船を割ることができる。どの順番で風船を割るのかは高橋君が自由に決定できる。 
 * どの風船についても、その風船を割ることによるペナルティが発生する。ペナルティ
 * はその風船が割られたときの高度と等しい整数値となる。高橋君が最終的に得る得点は
 * N個の風船のペナルティのうちの最大値となる。 
 * 高橋君が得ることのできる得点として考えられる最小値を求めよ。
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long INF = 1LL << 60; // 十分大きい値を1つ決める

int main()
{
    // 入力
    int N;
    cin >> N;
    vector<long long> h(N), s(N);
    for (int i = 0; i < N; ++i) { cin >> h[i] >> s[i]; }

    // 二分探索
    long long left = 0, right = INF;
    while (right - left > 1) {
        long long mid = (left + right) / 2;

        // 判定
        bool ok = true;
        vector<long long> t(N, 0); // 各風船をわるまでの時間制限
        // 要素数Nで、初期値0のvectorを時間制限として準備した
        
        for (int i = 0; i < N; ++i) {
            // そもそもmidが初期高度より低かったらfalse
            if (mid < h[i]) {
                ok = false;
            } else {
                t[i] = (mid - h[i]) / s[i];
            }
        }
        // 時間制限が差し迫っている順にソート
        sort(t.begin(), t.end());
        for (int i = 0; i < N; ++i) { 
            if (t[i] < i) {
                ok = false; // 時間切れ発生
            }
        }
        if (ok) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
}
