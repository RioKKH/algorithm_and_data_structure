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


auto for_each = [] (auto first, auto last, auto f)
{
    for (auto iter = first; iter != last; ++iter)
    {
        f(*iter);
    }
};

auto print_value = [] (auto v1, auto v2)
{
    cout << v1 << v2 << endl;
};


int main()
{
    int N = 10;
    Graph G(N);
    print_value(G[0][0].to, G[0][0].w);
}
