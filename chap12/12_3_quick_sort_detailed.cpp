#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 再帰の深さを追跡するためのグローバル変数
int depth = 0;

// インデントを生成する関数
string getIndent() { return string(depth * 4, ' '); }

// 配列の指定範囲を表示する関数
void printArray(const vector<int>& a, int left, int right, const string& label,
                int highlight = -1) {
    cout << getIndent() << label << "[" << left << ", " << right << "): ";
    for (int i = left; i < right; ++i) {
        if (i == highlight)
            cout << "[" << a[i] << "]";  // ハイライト
        else
            cout << a[i];
        if (i < right - 1) cout << " ";
    }
    cout << endl;
}

// 配列全体を表示する関数（処理範囲をハイライト）
void printFullArray(const vector<int>& a, int left, int right,
                    const string& label) {
    cout << getIndent() << label;
    for (int i = 0; i < a.size(); ++i) {
        if (i >= left && i < right)
            cout << "[" << a[i] << "]";
        else
            cout << " " << a[i] << " ";
        if (i < a.size() - 1) cout << " ";
    }
    cout << endl;
}

// 配列 a の区間 [left, right) をソートする
// [left, right) は、 left, left+1, ..., right-1 番目を表す
void QuickSort(vector<int>& a, int left, int right) {
    cout << getIndent() << "=== QUICK SORT CALLED ===" << endl;
    cout << getIndent() << "Range: [" << left << ", " << right << ")" << endl;
    printArray(a, left, right, "Current range: ");
    printFullArray(a, left, right, "Full array:    ");

    // ベースケース
    if (right - left <= 1) {
        cout << getIndent() << "Base case reached (size <= 1)" << endl;
        cout << getIndent() << "=========================" << endl;
        return;
    }

    cout << endl;
    cout << getIndent() << "=== DIVIDE PHASE (PARTITIONING) ===" << endl;

    // Pivot 選択
    int pivot_index = (left + right) / 2;  // 適当にここでは中点とする
    int pivot = a[pivot_index];
    cout << getIndent() << "1. Pivot selection:" << endl;
    cout << getIndent() << "   Pivot index: " << pivot_index
         << ", Pivot value: " << pivot << endl;
    printArray(a, left, right, "   Before pivot swap: ", pivot_index);

    // Pivot を右端に swap
    swap(a[pivot_index], a[right - 1]);  // pivot と右端を swap
    cout << getIndent() << "   Swap pivot with rightmost element" << endl;
    printArray(a, left, right, "   After pivot swap:  ", right - 1);

    cout << endl;
    cout << getIndent() << "2. Partitioning process:" << endl;
    cout << getIndent() << "   Goal: Move elements < " << pivot
         << " to left, >= " << pivot << " to right" << endl;

    int i = left;  // i は左詰めされた pivot 未満要素の右端を表す
    cout << getIndent() << "   i=" << i << " (boundary for elements < pivot)"
         << endl;

    for (int j = left; j < right - 1; ++j) {
        cout << getIndent() << "   j=" << j << ": Check a[" << j
             << "]=" << a[j];
        if (a[j] < pivot) {  // pivot 未満のものがあったら左に詰めていく
            cout << " < " << pivot << " → Swap with a[" << i << "]=" << a[i]
                 << endl;
            swap(a[i++], a[j]);
            cout << getIndent() << "    After swap: ";
            for (int k = left; k < right; ++k) {
                if (k == i - 1)
                    cout << "[" << a[k] << "] ";
                else if (k == j)
                    cout << "{" << a[k] << "} ";
                else
                    cout << a[k] << " ";
            }
            cout << "(boundary moved to i=" << i << ")" << endl;
        } else {
            cout << " >= " << pivot << " → No swap needed" << endl;
        }
    }

    cout << endl;
    cout << getIndent() << "3. Place pivot in correct position:" << endl;
    cout << getIndent() << "   Swap pivot a[" << (right - 1)
         << "]=" << a[right - 1] << " with a[" << i << "]=" << a[i] << endl;
    swap(a[i], a[right - 1]);  // pivot を適切な場所に挿入
    printArray(a, left, right, "   Final partitioned: ");

    cout << getIndent() << "   Partition complete!" << endl;
    cout << getIndent() << "   - Elements [" << left << ", " << i << ") are < "
         << pivot << endl;
    cout << getIndent() << "   - Element [" << i << "] is the pivot (" << pivot
         << ")" << endl;
    cout << getIndent() << "   - Elements (" << i << ", " << right
         << ") are >= " << pivot << endl;
    cout << getIndent() << "===================================" << endl;
    cout << endl;

    // 再帰的に解く
    cout << getIndent() << "=== CONQUER PHASE ===" << endl;

    // 左半分 (pivot 未満)
    if (i > left) {
        depth++;
        cout << getIndent() << ">>> Recursively sorting LEFT part [" << left
             << ", " << i << ") (< " << pivot << ")" << endl;
        QuickSort(a, left, i);  // 左半分 (pivot 未満)
        depth--;
    } else {
        cout << getIndent() << ">>> LEFT part [" << left << ", " << i
             << ") is empty, no recursion needed" << endl;
    }

    // 右半分 (pivot 以上)
    if (i + 1 < right) {
        depth++;
        cout << getIndent() << ">>> Recursively sorting RIGHT part [" << (i + 1)
             << ", " << right << ") (>= " << pivot << ")" << endl;
        QuickSort(a, i + 1, right);  // 左半分 (pivot 未満)
        depth--;
    } else {
        cout << getIndent() << ">>> RIGHT part [" << (i + 1) << ", " << right
             << ") is empty, no recursion needed" << endl;
    }

    cout << getIndent() << "=== COMBINE PHASE ===" << endl;
    cout << getIndent() << "No explicit combine needed (in-place sorting)"
         << endl;
    printArray(a, left, right, "Final sorted range: ");
    cout << getIndent() << "=====================" << endl;
    cout << endl;
}

int main() {
    cout << "=== QUICK SORT VISUALIZATION ===" << endl;

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

    // クイックソート
    QuickSort(a, 0, N);

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
