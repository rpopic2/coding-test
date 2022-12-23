#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num_commands;
    cin >> num_commands;
    vector<int> stack;
    for (int i = num_commands; i--;)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int arg;
            cin >> arg;
            stack.push_back(arg);
            continue;
        }
        else if (cmd == "pop")
        {
            if (stack.empty())
            {
                cout << -1;
            }
            else
            {
                cout << stack.back();
                stack.pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << stack.size();
        }
        else if (cmd == "empty")
        {
            cout << (int)stack.empty();
        }
        else if (cmd == "top")
        {
            if (stack.empty())
            {
                cout << -1;
            }
            else cout << stack.back();
        }
        else throw;
        cout << '\n';
    }
}
