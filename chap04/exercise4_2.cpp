/**
 * トリボナッチ数列
 */

#include <iostream>
#include <vector>
using namespace std;

// tri(N)の答えをメモ化する配列
vector<long long> memo;

long long tri(int N) {
    // ベースケース
    if (N == 0) {
        return 0;
    } else if (N == 1) {
        return 0;
    } else if (N == 2) {
        return 1;
    }

    // メモをチェックする
    // 既に計算済みであれば、答えをリターンする
    if (memo[N] != -1) {
        return memo[N];
    }

    // 答えをメモ化しながら、再帰呼び出しを実行する
    return memo[N] = tri(N-1) + tri(N-2) + tri(N-3);
}

int main() {
    int N;
    cin >> N;
    // メモ化用配列を-1で初期化する
    memo.assign(N+1, -1);

    // tri(N)を呼び出す
   cout << tri(N) << endl;

    // memo[0], ..., memo[N]に答えが格納されている
    for (int i = 3; i < N; ++i) {
        cout << i << " 項目: " << memo[i] << endl;
    }
}
