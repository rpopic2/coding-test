#include <iostream>
int main()
{

    return 0;
}

class Element
{
public:
    Element* front;
    Element(Element* front)
    {
        this->front = front;
    }
};

class List
{
public:
    void Add(){
        new Element(nullptr);
    }
private:
     
};

