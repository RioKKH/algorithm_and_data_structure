#include <iostream>
#include <vector>

/**
 * 0 <= X, Y, Z <= K
 * X + Y + Z = N
 */
int main(int argc, char const* argv[])
{
    // 入力受け取り
    int K, N;
    std::cin >> K >> N;

    int count = 0;
    for (int X = 0; X <= K; ++X) {
        for (int Y = 0; Y <= K; ++Y) {
            int Z = N - X - Y;
            if ((Z >= 0) && (Z <= K)) {
                ++count;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}


