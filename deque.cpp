#include "error.cpp"
class deque
{
private:
    struct node
    {
        node *next,*prev;
        int item;
        node(int item,node *prev=NULL,node *next=NULL):item(item),next(next),prev(prev)
        {}
    };
    
    node *front,*rear;
public:
    deque()
    {
        front=NULL;
        rear=NULL;
    }
    deque(int num);
    deque(deque &);
    ~deque();
    bool insertF(int);
    bool insertR(int);
    bool delF();
    bool delR();
    int getF()
    {
        return front->item;
    }
    int getR()
    {
        return rear->item;
    }
    bool isEmpty();
    friend ostream & operator<<(ostream &,deque &);
};
ostream & operator<<(ostream &cout,deque &obj)
{
    deque::node *ptr=obj.front;
    cout<<"[";
    while(ptr)
    {
        cout<<ptr->item<<',';
        ptr=ptr->next;
    }
    cout<<"]\n";
    return cout;
}
deque::deque(int num)
{
    rear=new node(num);
    front=rear;
}
deque::~deque()
{
    while(delF());
}
bool deque::delF()
{
    if(!front)
        return false;
    node *ptr=front;
    front=front->next;
    delete ptr;
    if(front==NULL)
        rear=NULL;
    else
        front->prev=NULL;
    return true;
}
bool deque::insertF(int item)
{
    if(!front)
        front=(rear=new node(item));
    else{
        front->prev=new node(item,NULL,front);
        front=front->prev;
    }
    return true;
}
bool deque::insertR(int item)
{
    if(!front)
        front=(rear=new node(item));
    else
    {
        rear->next=new node(item,rear,NULL);
        rear=rear->next;
    }
    return true;
}
bool deque::delR()
{
    if(!rear)
        return false;
    else
    {
        deque::node *ptr=rear;
        rear=rear->prev;
        rear->next=NULL;
        delete ptr;
    }
    if(rear==NULL)
        front=NULL;
    return true;
}
bool deque::isEmpty()
{
    return !rear;
}
deque::deque(deque & obj)
{
    rear=NULL;
    front=NULL;
    for(node *ptr=obj.front;ptr;ptr=ptr->next)
        insertR(ptr->item);
}