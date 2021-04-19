/**
 * 区間スケジューリング問題に対する貪欲法
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 区間をpair<int, int>で表す
using Interval = pair<int, int>;

// 区間を終端時刻で大小比較する関数
bool cmp(const Interval &a, const Interval &b)
{
    return a.second < b.second;
}

int main()
{
    // 入力
    int N;
    cin >> N;
    // Intervalを要素とする、要素数Nのvector
    vector<Interval> inter(N);
    for (int i = 0; i < N; ++i) {
        cin >> inter[i].first >> inter[i].second;
    }

    // 終端時刻が早い順にソートする
    sort(inter.begin(), inter.end(), cmp);

    // 貪欲に選ぶ
    int res = 0;
    int current_end_time = 0;
    for (int i = 0; i < N; ++i) {
        // 最後に選んだ区間とかぶるのは除く
        if (inter[i].first < current_end_time) {
            continue;
            // 下の処理には進まずfor loopの次のインデックスの処理に進む
        }
        ++res;
        current_end_time = inter[i].second;
    }
    cout << res << endl;
}


