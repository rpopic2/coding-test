#include <iostream>
using namespace std;

constexpr size_t maxSize = 100;
int n, m;
void cinMat(int mat[maxSize][maxSize]);

int main()
{
    cin >> n >> m;
    int matA[maxSize][maxSize], matB[maxSize][maxSize], matResult[maxSize][maxSize];
    cinMat(matA);
    cinMat(matB);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matResult[i][j] = matA[i][j] + matB[i][j];
            cout << matResult[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void cinMat(int mat[maxSize][maxSize])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
}
