#include <cmath>
#include <iostream>
#include <vector>
// using namespace std;

// 2点 (x1, y1)と(x2, y2)との距離を求める関数
double calc_dist(double x1, double y1, double x2, double y2) {
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(int argc, char const* argv[]) {
    // 入力データを受け取る
    int N;
    std::cin >> N;
    std::vector<double> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> x[i] >> y[i];
    }
    // 求める値を、十分大きい値で初期化しておく
    double minimum_dist = 1E10f;

    // 探索開始
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // NxN行列の上三角行列から対角成分を除いた範囲について処理
            // 半分全探索を実施する。より効率的なアルゴリズムとして
            // 分割統治法(divide-and-conquer method)というアルゴリズムもある。
            // (x[j], y[j])と(x[j], y[j])との距離
            double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);

            // 暫定最小値 minimum_distをdist_i_jと比べる
            if (dist_i_j < minimum_dist) {
                minimum_dist = dist_i_j;
            }
        }
    }
    std::cout << minimum_dist << std::endl;

    return 0;
}
