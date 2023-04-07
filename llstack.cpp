#include</home/hp/Softwares/DSA/error.cpp>
class stack
{
    private:
        struct node
        {
            node *next,*prev;
            int item;
            node(int  item,node *next,node *prev):item(item),next(next),prev(prev)
            {}
        };
        node *last;
    public:
        stack():last(NULL){};
        stack(int num)
        {
            last=new node(num,NULL,NULL);
        }
        ~stack();
        bool push(int num);
        int peek();
        bool pop();

};
bool stack::push(int num)
{
    if(!last)
    {
        last=new node(num,NULL,NULL);
        return true;
    }
    last->next=new node(num,NULL,last);
    last=last->next;
    return true;
}
bool stack::pop()
{
    if(last==NULL)
        return true;
    if(last->prev==NULL)
    {
        delete last;
        last=NULL;
        return true;
    }
    else{
        node *prev=last;
        last=last->prev;
        last->next=NULL;
        delete prev;
    }
    return false;
}
int stack::peek()
{
    if(last)
        return last->item;
    else
        throw *(new NodeNotMade);
}
stack::~stack()
{
    while(last)
        pop();
}
