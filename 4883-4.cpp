#include <climits>
#include <iostream>
#include <array>
#include <vector>
#include <optional>
using namespace std;
constexpr int COL = 3;
struct node
{
    int cost = 0, i = -1, j = -1;
};
typedef vector<array<node, COL>> matrix;
matrix dp;
optional<node> opt_min(optional<node> &lhs, optional<node> &rhs)
{
    if (!rhs.has_value()) return lhs;
    else if (!lhs.has_value()) return rhs;
    return lhs.value().cost > rhs.value().cost ? rhs : lhs;
}
optional<node> try_get(const matrix &mat, const int i, const int j)
{
    if (i == 0 && j == 0) return{};
    if (i < 0 || j < 0) return{};
    if (i >= mat.size() || j >= COL) return{};
    return {mat[i][j]};
}
void step(const matrix &mat, int i, int j)
{
    auto orig_cost = mat[i][j].cost;
    optional<node> min;
    auto a = try_get(mat, i, j - 1);
    a = try_get(mat, i - 1, j - 1);
    min = opt_min(min, a);
    a = try_get(mat, i - 1, j);
    min = opt_min(min, a);
    a = try_get(mat, i - 1, j + 1);
    min = opt_min(min, a);
    if (min.has_value())
    {
        auto val = min.value();
        i = val.i;
        j = val.j;
        dp[i][j] = {orig_cost + val.cost};
    }
}
int main()
{
    int row;
    cin >> row;
    matrix mat;
    for (int i = 0; i < row; ++i)
    {
        array<node, COL> a;
        for (int j = 0; j < COL; ++j)
        {
            cin >> a[j].cost;
            a[j].i = i;
            a[j].j = j;
        }
        mat.push_back(a);
    }
    int i = row - 1, j = 1;
    dp.resize(row);
    dp[i][j].cost = mat[i][j].cost;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < COL; ++i)
        {
            step(mat, i , j);
        }
    }
    cout << endl << dp[i][j].cost;
}
