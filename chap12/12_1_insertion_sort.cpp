#include <iostream>
#include <vector>
using namespace std;

// 配列aをソートする
void INsertionSort(vector<int> &a) {
    int N = (int)a.size();
    for (int i = 1; i < N; ++i) { // 0番目はソート済み
        int v = a[i]; // 挿入したい値

        // vを挿入する適切な場所jを探す
        int j = 1;
        for (; j > 0; --j) {
            if (a[j - 1] > v) { // vより大きいものは１つ後ろに移す
                a[j] = a[j - 1];
            }
            else break; // v以下になったら止める
        }
        a[j] = v; // 最後にj番目にvを持ってくる
    }
}

// ソート結果を出力する関数
void print(vector<int> &a) {
    int N = (int)a.size();
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    // 入力
    int N; //要素数
    cin >> N;
    vector<int> a(N); // 要素数Nの配列
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 挿入ソート
    INsertionSort(a);
    print(a);
}




