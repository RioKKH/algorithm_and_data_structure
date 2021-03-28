#include <iostream>

int GCD(int m, int n)
{
    std::cout << "GCD(" << m << "," << n << ") を呼び出しました" << std::endl;
    // ベースケース
    if (n == 0) {
        return m;
    } else {
        // 再帰呼び出し
        return GCD(n, m % n);
    }
}

int main() {
    std::cout << GCD(51, 15) << std::endl; // 3が出力される
    std::cout << GCD(15, 51) << std::endl; // 3が出力される
}
