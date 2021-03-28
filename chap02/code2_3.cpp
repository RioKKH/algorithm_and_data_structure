#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    int N;
    cin >> N;

    for (int i = 2; i <= N; i+=2) {
        cout << i << endl;
    }
    return 0;
}
