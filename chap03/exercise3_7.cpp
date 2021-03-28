#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const* argv[])
{
    std::string S;
    std::cin >> S;
    int N = S.size();

    // N-1箇所の隙間に「+」を入れるかどうかをすべて試す
    long long res = 0;
    // 2^{N-1}通りについてforループを回す
    for (int bit = 0; bit < (1 << (N-1)); ++bit) {
        // tmp: 「+」と「+」の間の値を表す変数
        long long tmp = 0;
        // 長さN-1
        for (int i = 0; i < N-1; ++i) {
            tmp *= 10;
            std::cout << "S[i] : " << S[i] << ", "
                      << " S[i] - '0' : " << S[i] - '0';
            tmp += S[i] - '0';
            std::cout << ", tmp : " << tmp;
            std::cout << tmp << std::endl;

            // 「+」を挿入するときに、答えにtmp を加算して、tmpを0に初期化する
            if (bit & (1 << i)) {
                // trueになった場合、＋があったと判断してresにtmpを足す。
                // 足したので、tmpは0にクリアする
                res += tmp;
                std::cout << "result: " << res << std::endl;
                tmp = 0;
            }
        }
        // 最後の「+」から残りの部分を答えに加算
        tmp *= 10;
        tmp += S.back() - '0';
        res += tmp;
    }
    std::cout << res << std::endl;
    return 0;
}


