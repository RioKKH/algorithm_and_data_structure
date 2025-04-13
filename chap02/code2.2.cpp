#include <iostream>

// 計算量O(N^2)のコード
// time ./a.out <<< 100
int main() {
    int N;
    std::cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ++count;
        }
    }

    return 0;
}
