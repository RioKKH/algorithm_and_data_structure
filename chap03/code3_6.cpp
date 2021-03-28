#include <iostream>
#include <vector>
using namespace std;

/**
 * 計算量は
 * O(N) = O(2^N * N)
 *      = O(N2^N)
 */
int main(int argc, char const* argv[])
{
    // 入力受け取り
    int N, W;
    cin >> N >> W;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) { cin >> a[i]; }

    // bit は2^N通りの部分集合全体を動く
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        int sum = 0; // 部分集合に含まれる要素の和
        for (int i = 0; i < N; ++i) {
            // i番目の要素 a[i] が部分集合に含まれているかどうか
            if (bit & (1 << i)) {
                sum += a[i];
            }
        }

        // sumがWに一致するかどうか
        if (sum == W) { exist = true; }
    }
    if (exist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
