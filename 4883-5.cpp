#include <iostream>
#include <vector>
#include <array>
#include <optional>
#include <algorithm>
using namespace std;
constexpr int COL = 3;
typedef vector<array<int, COL>> matrix;

class pos
{
public:
    pos(int _i, int _j, matrix *_mat)
    {
        i = max(-1, _i);
        j = max(-1, _j);
        mat = _mat;
        if (_j > COL) i = j = -1;
    }
    pos() { i = j = -1; }
    int l() { return (*mat)[i][j - 1]; }
    int ul() { return (*mat)[ i - 1][ j - 1 ]; }
    int um() { return (*mat)[ i - 1][ j ]; }
    int ur() { return (*mat)[ i - 1][ j + 1 ]; }

    int i = -1, j = -1;
    matrix *mat;
};
int min(int i, int j, int k, int l)
{
    return std::min(min(i, j), min(k, l));
}

class graph
{
public:
    graph(int _rows)
    {
        vec.resize(_rows);
        dp.resize(_rows);
        rows = _rows;
    }
    friend istream &operator>>(istream &istr, graph &mat)
    {
        array<int, COL> a;
        for (int i = 0, s = mat.vec.size(); i < s; ++i)
        {
            for (int j = 0; j < COL; ++j) istr >> a[j];
            mat.vec[i] = a;
        }
        return istr;
    }
    optional<int> at(pos p);
    int traverse_from(pos p);
private:
    int rows = 0;
    vector<array<int, COL>> vec;
    vector<array<int, COL>> dp;
};
optional<int> graph::at(pos p)
{
    if (p.j > rows) return {};
    else if (p.i == -1 || p.j == -1) return {};
    return {vec[p.i][p.j]};
}
int graph::traverse_from(pos p)
{
    dp[p.i][p.j] = at(p).value();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            pos q{i, j, &vec};
            dp[q.i][q.j] =  min(q.l(), q.ul(), q.um(), q.ur());
        }
    }

    return dp[rows - 1][1];
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) return 0;
        graph mat(n);
        cin >> mat;
        cout << mat.traverse_from({0, 1, nullptr});
    }
}
