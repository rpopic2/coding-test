#include <string>
#include <vector>
#include <map>

using namespace std;

constexpr int PRICE = 100;
constexpr int TAKE = 10;

class node
{
public:
    node(node* parent_ptr)
    {
        p = parent_ptr;
    }
    int getv() { return v; }
    void sell(int amount)
    {
        int money = amount * PRICE;
        earn(money);
    }
private:
    node* p;
    int v = 0;
    void earn(int money)
    {
        int togive = p == nullptr ? 0 : money / TAKE;
        v += money - togive;
        if (togive == 0) return;
        p->earn(togive);
    }
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    map<string, node> mp;
    node rt(nullptr);
    
    mp.insert(pair<string, node>("-", rt));
    for (int i = 0, vs = enroll.size(); i < vs; i++)
    {
        string enrname = enroll[i];
        string refname = referral[i];
        node* p = &mp.at(refname);
        node n(p);
        mp.insert(pair<string, node>(enrname, n));
    }
    
    for (int i = 0, vs = seller.size(); i < vs; i++)
    {
        mp.at(seller[i]).sell(amount[i]);
    }
    
    vector<int> a;
    for (const auto& name : enroll)
    {
        auto v = mp.at(name).getv();
        a.push_back(v);
    }
    return a;
}
