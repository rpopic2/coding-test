#include <iostream>
#include <vector>

using namespace std;

const string eof = "#";
const string vowels = "aeiou";
int vc = vowels.length();
const string delims = ",.!?";

int main()
{
    vector<int> counts;
    string curline;

    while (true)
    {
        cin >> curline;
        if (curline == eof) break;
        int cl = curline.length();
        int cc = 0;
        for (int i = 0; i < cl; i++)
        {
            for (int j = 0; j < vc; j++)
            {
                bool b = curline[i] == vowels[j];
                if(b) cc++;
            }
        }
        counts.push_back(cc);
    }

    for (int i = 0; i < counts.size(); i++)
    {
        cout << counts[i] << "\n";
    }
}

