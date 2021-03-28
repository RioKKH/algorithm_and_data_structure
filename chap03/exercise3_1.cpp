#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const* argv[])
{
    // 入力を受け取る
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) { cin >> a[i]; }

    // 線形探索
    int found_id = -1; // 初期値は−1などの有り得ない値に
    for (int i = 0; i < N; i++) {
        if (a[i] == v) { 
            // 見つかったら添字を記録.
            // この添字が最大のものになることを確認する.つまりa[i] == v
            // を満たすものが見つかる度にfound_idがその時の添字のiに更新
            // されるため、一番最後に見つかったi、つまり最大のiになる。
            found_id = i; 
            // break; // breakをコメントアウトする
        }
    }

    cout << found_id << endl;

    return 0;
}

