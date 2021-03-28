#include <iostream>
#include <vector>
using namespace std;

const int INF = 20000000; // 十分に大きな値にする

/**
 * N個の相異なる整数が与えられたときに、このうつ2番目に小さい値を
 * もとめるO(N)のアルゴリズムを設計する
 */
int main(int argc, char const* argv[])
{
    // 入力を受け取る
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) { cin >> a[i]; }


    // 線形探索
    int smallest_value = INF;
    int second_smallest_value = INF;
    for (int i = 0; i < N; i++) {
        if (a[i] == v) { 
            if (a[i] < smallest_value) {
                // 先ず現在の一番小さいとされていた値が1つずれて2番目に小さい
                // 数値となるので、最小値を書き換える前に2番目に小さい数値を
                // 更新する
                second_smallest_value = smallest_value;
                // その上で最小値をa[i]の値で更新する。更新する順番が大切
                smallest_value = a[i];
            } 
            else if (a[i] < second_smallest_value) {
                second_smallest_value = a[i];
            }
        }
    }

    cout << second_smallest_value << endl;

    return 0;
}

