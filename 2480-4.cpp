#include <functional>
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr int DICES = 3;
constexpr int BONUS[DICES] = { 0, 1000, 10000 };
constexpr int DICE_SCORE[DICES] = { 100, 100, 1000 };
int main()
{
      array<int, DICES> a;
      for (int i = 0; i < DICES; ++i)
      {
          int tmp;
          cin >> tmp;
          a[i] = tmp;
      }
      sort(a.begin(), a.end(), greater<int>());
      auto i = count(a.begin(), a.end(), a[1]) - 1;
      auto answer = BONUS[i] + DICE_SCORE[i] * a[i];
      cout << answer;
}
