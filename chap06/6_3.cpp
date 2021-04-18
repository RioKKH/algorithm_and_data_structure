#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Start Game!" << endl;

    // Aさんの数の候補おｗ表す区間を[left, right)と表す
    int left = 20, right = 36;

    // Aさんの数を1つに絞れないうちは繰り返す
    while (right - left > 1) {
        int mid = left + (right - left) / 2; // 区間の真ん中

        // mid以上かを聞いて、回答をyes/noで受け取る
        cout << "Is the age less than " << mid << " ? (yes / no)" << endl;
        string ans;
        cin >> ans;

        // 回答に応じて、有りうる数の範囲を絞る
        if (ans == "yes") { right = mid; }
        else { left = mid; }
    }

    // ずばり当てる！
    cout << "The age is " << left << "!" << endl;
}
