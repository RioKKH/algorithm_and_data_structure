#include <iostream>
using namespace std;

int tri(int N) {
    //再帰関数を呼び出したことを報告する
    std::cout << "tri(" << N << ") を呼び出した" << std::endl;

    // ベースケース
    if (N == 0) {
        return 0;
    } else if (N == 1) {
        return 1;
    } else if (N == 2) {
        return 1;
    }
    // 再帰呼び出し
    return tri(N - 1) + tri(N - 2) + tri(N - 3);
}

int main() {
    int N;
    cin >> N;
    cout << tri(N) << endl;

    return 0;
}


