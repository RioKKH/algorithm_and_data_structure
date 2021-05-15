#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int to;
    long long w;

    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

auto print = [](auto x){ cout << x << endl; };

int main()
{
    int N = 10;
    Graph G(N);
    print(G);
}
