#include </home/hp/Softwares/DSA/Array.cpp>

class stack
{
    private:
        array stac;
    public:
        void CreateStack(int);
        void pop();
        int peek();
        void push(int);
};
void stack::CreateStack(int size)
{
    stac.createArray(size);
}
void stack::pop()
{
    stac.del(stac.getLastIndex());
}
int stack::peek()
{
    return stac.get(stac.getLastIndex());
}
void stack::push(int num)
{
    stac.append(num);
}

int main()
{
    stack a;
    a.CreateStack(8);
    a.push(1350);
    a.push(450);
    a.pop();
    cout<<a.peek();
    return 0;
}