#include <iostream>

bool is_prime(int N) {
    if (N <= 1) {
        return false;
    }

    for (int p = 2; p * p <= N; ++p) {
        if (N % p == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const* argv[])
{
    
    int N = 0;
    std::cin >> N;
    if (is_prime(N)) {
        std::cout << N << " is a prime number" << std::endl;
    } else {
        std::cout << N << " is not a prime number" << std::endl;
    }
    return 0;
}
