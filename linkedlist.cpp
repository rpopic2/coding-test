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
    template<typename... Args>
    list(const Args&... vs)
    {
        add(vs...);
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

    int deleteAt(int index)
    {
        element* pcur = pfirst;
        element* pprev = nullptr;
        for (int i = 0; i < index; i++)
        {
            pprev = pcur;
            pcur = pcur->next;
        }
        if (pprev == nullptr)
        {
            pfirst = pcur->next;
        }
        else
        {
            pprev->next = pcur->next;
        }
        int r = pcur->v;
        delete pcur;
        return r; 
    }

    int at(int index)
    {
        return elemat(index)->v;
    }
private:
    element* pfirst = nullptr;
    element* plast = nullptr;
    element* elemat(int index)
    {
        element* pcur = pfirst;
        for (int i = 0; i < index; i++)
        {
            pcur = pcur->next;
        }
        return pcur;
    }
};

int main()
{
    list ls(3, 4, 6);
    cout << ls.at(2);
    ls.deleteAt(2);
    cout << ls.at(1);
}

