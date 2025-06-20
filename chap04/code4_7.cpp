#include <iostream>
#include <vector>

int main(int argc, char const* argv[]) {
    std::vector<long long> F(50);
    F[0] = 0, F[1] = 1;
    for (int N = 2; N < 50; ++N) {
        F[N] = F[N - 1] + F[N - 2];
        std::cout << N << " 項目： " << F[N] << std::endl;
    }
    return 0;
}
