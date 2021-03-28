#include <iostream>
#include <vector>
using namespace std;

/**
 * シングルループの線形全探索なのでO(N)となる
 */
int main(int argc, char const* argv[])
{
    // 入力を受け取る
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) { cin >> a[i]; }

    // 線形探索
    int found_id = 0; // 初期値は0にする
    for (int i = 0; i < N; i++) {
        if (a[i] == v) { 
            // 見つかったらfound_idを+1する。
            ++found_id; 
        }
    }

    cout << found_id << endl;

    return 0;
}

