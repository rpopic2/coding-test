#include <iostream>

using namespace std;
template<typename T>
class element
{
public:
    element* next;
    T v;
    element(T val)
    {
        v = val;
    }
};

template<typename T>
class list
{
public:
    int len()
    {
        return len_;
    }
    template<typename... Args>
    list(const Args&... vs)
    {
        add(vs...);
    }
    void add(){}
    template<typename U, typename... Args>
    element<T>* add(const U& v, const Args&... vs)
    {
        auto e = new element<T>(v);
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
        len_++;
        add(vs...);
        return plast;
    }

    int deleteAt(int index)
    {
        element<T>* pcur = pfirst;
        element<T>* pprev = nullptr;
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
        len_--;
        return r; 
    }

    int at(int index)
    {
        return elemat(index)->v;
    }
private:
    int len_ = 0;
    element<T>* pfirst = nullptr;
    element<T>* plast = nullptr;
    element<T>* elemat(int index)
    {
        element<T>* pcur = pfirst;
        for (int i = 0; i < index; i++)
        {
            pcur = pcur->next;
        }
        return pcur;
    }
};

int main()
{
    list<int> ls(3, 4, 6);
    cout << ls.at(2);
    cout << ls.len();
    ls.deleteAt(1);
    cout << ls.at(1);
    cout << ls.len();
}

