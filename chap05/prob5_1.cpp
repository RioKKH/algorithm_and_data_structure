#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template<class T> inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

// 入力
int N;
// a[i], b[i], c[i]をそれぞれまとめてa[i][0], b[i][1], c[i][2]にしてしまう
long long a[100010][3];

// DPテーブル
long long dp[100010][3]

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    // 初期化は既に0に初期化される
    // 初期条件も既に0でOK
    
    // ループ
    for (int i = 0; i < N; ++i) {
        for (int j =0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) {
                    continue;
                }
                chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    } 

    // 答え
    long long res = 0;
    for (int j = 0; j < 3; ++j) {
        chmax(res, dp[N][j]);
    }

    cout << res << endl;
}


