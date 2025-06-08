#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 再帰の深さを追跡するためのグローバル変数
int depth = 0;

// インデントを生成する関数
string getIndent() { return string(depth * 4, ' '); }

// 配列の指定範囲を表示する関数
void printArray(const vector<int>& a, int left, int right,
                const string& label) {
    cout << getIndent() << label << "[" << left << ", " << right << "): ";
    for (int i = left; i < right; ++i) {
        cout << a[i];
        if (i < right - 1) cout << " ";
    }
    cout << endl;
}

// 配列 a の区間 [left, right) をマージソートする
// [left, right) は、left, left+1, ..., right-1 番目を表す
void MergeSort(vector<int>& a, int left, int right) {
    cout << getIndent() << "=== DIVIDE PHASE ===" << endl;
    cout << getIndent() << "MergeSort called for range [" << left << ", "
         << right << ")" << endl;
    printArray(a, left, right, "Current array: ");

    // ベースケース
    if (right - left == 1) {
        cout << getIndent() << "Base case reached (size = 1)" << endl;
        cout << getIndent() << "====================" << endl;
        return;
    }

    int mid = left + (right - left) / 2;
    cout << getIndent() << "Dividing at mid = " << mid << endl;
    cout << getIndent() << "Left half: [" << left << ", " << mid << ")" << endl;
    cout << getIndent() << "Right half: [" << mid << ", " << right << ")"
         << endl;
    cout << endl;

    // 左半分 [left, mid) をソート
    depth++;
    cout << getIndent() << ">>> Recursively sorting LEFT half [" << left << ", "
         << mid << ")" << endl;
    MergeSort(a, left, mid);
    depth--;

    // 右半分 [mid, right) をソート
    depth++;
    cout << getIndent() << ">>> Recursively sorting RIGHT half [" << mid << ", "
         << right << ")" << endl;
    MergeSort(a, mid, right);
    depth--;

    cout << endl;
    cout << getIndent() << "=== CONQUER PHASE ===" << endl;
    cout << getIndent() << "Merging [" << left << ", " << mid << ") and ["
         << mid << ", " << right << ")" << endl;
    printArray(a, left, mid, "Left sorted: ");
    printArray(a, mid, right, "Right sorted: ");

    // 一旦「左」と「右」のソート結果をコピーしておく(右側は左右反転)
    vector<int> buf;
    for (int i = left; i < mid; ++i) buf.push_back(a[i]);
    for (int i = right - 1; i >= mid; --i) buf.push_back(a[i]);

    cout << getIndent() << "Buffer created: ";
    for (int i = 0; i < buf.size(); ++i) {
        cout << buf[i];
        if (i < buf.size() - 1) cout << " ";
    }
    cout << " (right half is reversed)" << endl;

    // 併合する
    int index_left = 0;                     // 左側の添え字
    int index_right = (int)buf.size() - 1;  // 右側の添え字

    cout << getIndent() << "Merging process:" << endl;
    for (int i = left; i < right; ++i) {
        cout << getIndent() << "  Step " << (i - left + 1) << ": ";
        cout << "Compare buf[" << index_left << "]=" << buf[index_left]
             << " vs buf[" << index_right << "]=" << buf[index_right];

        // 左側採用
        if (buf[index_left] <= buf[index_right]) {
            a[i] = buf[index_left++];
            cout << " → Choose " << a[i] << " (from left)" << endl;
        }
        // 右側採用
        else {
            a[i] = buf[index_right--];
            cout << " → Choose " << a[i] << " (from right)" << endl;
        }
    }

    printArray(a, left, right, "Merged result: ");
    cout << getIndent() << "==================" << endl;
    cout << endl;
}

int main() {
    // 入力
    int N;  // 要素数
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    cout << "\nInitial array: ";
    for (int i = 0; i < N; ++i) {
        cout << a[i];
        if (i < N - 1) cout << " ";
    }
    cout << "\n" << endl;

    // マージソート
    MergeSort(a, 0, N);

    // ソート後
    cout << "=== FINAL RESULT ===" << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < N; ++i) {
        cout << a[i];
        if (i < N - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
