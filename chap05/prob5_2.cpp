#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 入力
int n, A;
int a[110];

// DPテーブル
bool dp[110][10010];

int main()
{
    cin >> n >> A;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    memset(dp, 0, sizeof(dp));  // 一旦全てfalseにする
    dp[0][0] = true;            // dp[0][0]だけtrueにする

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= A; ++j) {
            dp[i+1][j] |= dp[i][j];
            if (j >= a[i]) {
                dp[i+1][j] |= dp[i][j-a[i]];
            }
        }
    }

    if (dp[n][A]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
