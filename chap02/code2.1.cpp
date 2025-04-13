#include <iostream>

// 計算量O(N)のコード
// time ./a.out <<< 100
int main() {
    int N;
    std::cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        ++count;
    }

    return 0;
}
