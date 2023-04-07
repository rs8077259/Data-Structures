#include</home/hp/Softwares/DSA/error.cpp>
class queue{
    protected:
        struct node
        {
            node *next;
            int item;
            node(int item,node *next=NULL):item(item),next(next)
            {}
        };
        node *front,*rear;
    public:
        queue():front(NULL),rear(NULL)
        {}
        queue(int num)
        {
            front=new node(num);
            rear=front;
        }
        queue(queue &);
        ~queue();

        bool insert(int);
        int getRear()
        {
            return rear->item;
        }
        int getFront()
        {
            return front->item;
        }
        void del();
        int count();
        queue & operator=(queue &);

};

bool queue::insert(int num)
{
    if(!rear)
    {
        front=new node(num);
        rear=front;
        return true;
    }
    rear->next=new node(num);
    rear=rear->next;
    return true;
}
void queue::del()
{
    node *fron=front;
    front=front->next;
    delete fron;
    if(!front)
        rear=NULL;
}
int queue::count()
{
    node *p=front;
    int a=0;
    for(;p;p=p->next,a++);
    return a;
}
queue::~queue()
{
    while(front)
        del();
}
queue::queue(queue &obj)
{
    rear=NULL;
    front=NULL;
    node *p=obj.front;
    for (;p;p=p->next)
        insert(p->item);
    
}
queue & queue::operator=(queue & obj)
{
    while(front)
        del();
    node *p=obj.front;
    for (;p;p=p->next)
        insert(p->item);
    return obj;
}
int main()
{
    queue a;
    a.insert(90);
    a.insert(80);
    a.insert(100);
    queue b;
    b=a;
    cout<<a.getRear()<<a.getFront();
    return 0;
}