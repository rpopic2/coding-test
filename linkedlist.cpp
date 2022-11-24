#include <iostream>

using namespace std;
class element
{
public:
    element* next;
    int v;
    element(int val)
    {
        v = val;
    }
};

class list
{
public:
    element* pfirst = nullptr;
    element* plast = nullptr;

    list()
    {
    }

    void add(){}
    template<typename T, typename... Args>
    element* add(const T& v, const Args&... vs)
    {
        auto e = new element(v);
        if(pfirst == 0)
        {
            pfirst = e;
            plast = e;
        }
        else
        {
            plast->next = e;
            plast = e;
        }
        add(vs...);
        return plast;
    }
    int at(int index)
    {
        element* pcur = pfirst;
        for (int i = 0; i < index; i++)
        {
            pcur = pcur->next;
        }
        return pcur->v;
    }
//private:
};

int main()
{
    list ls;
    ls.add(3, 5, 6);
    cout << ls.at(2);
    //cout << ls;
    //cout << ls.at(1);
    //l.add(3);
    //auto e = l.add(5);
    //auto ev = e->front->v;
    //std::cout << ev;
}

