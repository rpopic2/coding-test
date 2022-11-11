#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int i, j;
   vector<int> v, w;
   while(true)
   {
       cin >> i >> j;
       if(i == 0 && j == 0) break;
       v.push_back(i);
       w.push_back(j);
   }
   size_t s = v.size();
   for (int k = 0; k < s; k++)
   {
       string s = v[k] > w[k] ? "Yes" : "No";
       cout << s << "\n";
   }
}
