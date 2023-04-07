#include</home/hp/Softwares/DSA/error.cpp>
using namespace std;
struct node
{
    node *prev,*next;
    int item;
    node()
    {}
    node(int item,node *pe=NULL,node *next=NULL)
    {
        prev=pe;
        this->item=item;
        this->next=next;
    }
};
class DLL
{
    public:
        node *start;
    public:
        DLL()
        {
            start=NULL;
        }
        DLL(int num)
        {
            start=new node(num);
        }
        DLL(DLL &copy);
        ~DLL();
        DLL operator=(DLL&);
        void InsertAtStart(int);
        void InsertAtEnd(int);
        int Find(int num);
        void Insert(int,int);
        void InsertAfter(int index,int value);
        void DelFirst();
        void DelLast();
        void del(int node);
        friend ostream& operator<<(ostream&,DLL&);
};
ostream& operator<<(ostream& cout,DLL &obj)
{
    cout<<'[';
    node *str=obj.start;
    for(;str!=NULL;str=str->next)
        cout<<str->item<<',';
    cout<<"]\n";
    return cout;
}
void DLL::InsertAtStart(int num)
{
    start=new node(num,NULL,start);
    if(start->next)
    start->next->prev=start;
}
void DLL::InsertAtEnd(int num)
{
    if(start)
    {
    node *a=start;
    for(;a->next;a=a->next);
    a->next=new node(num,a->prev?a->prev->next:start);
    }
    else
        InsertAtStart(num);
}
int DLL::Find(int num)
{
    int a=0;
    node *star=start;
    for(;star->next&&star->item!=num;star=star->next,a++);
    return a==0?star->item==num?0:-1:a;
}
void DLL::InsertAfter(int index,int num)
{
    if(index==-1)
    {
        InsertAtStart(num);
    }
    else{
        int a=0;
        node *poi=start;
        for(int a=0;a!=index;poi=poi->next,a++);
        poi->next=new node(num,poi,poi->next);
    }
}
void DLL::DelFirst()
{
    if(!start)
        throw 0;
    node *star=start;
    start=star->next;
    delete star;
    if(start)
        start->prev=NULL;
}
void DLL::DelLast()
{
    node *str=start;
    for(;str->next->next;str=str->next);
    delete str->next->next;
    str->next=NULL;

}
void DLL::del(int nod)
{
    if(nod)
    {
    int a=0;
    node *no=start,*n;
    for(;nod!=a;no=no->next,a++);
    
    no=no->prev;
    n=no;
    n=no->next;
    no->next=no->next->next;
    if(no->next)
    no->next->prev=n->prev;
    delete n;
    }
    else
        DelFirst();

}
DLL::DLL(DLL & copy)
{
    start=new node(copy.start->item);
    node *a=start,*b=copy.start;
    for(;b->next;)
    {
        b=b->next;
        a->next=new node(b->item,a);
        a=a->next;
    }
}
DLL::~DLL()
{
    while(start)
    {
        DelFirst();
    }
}
DLL DLL::operator=(DLL &copy)
{
    while(start)
        DelFirst();
    start=new node(copy.start->item);
    node *a=start,*b=copy.start;
    for(;b->next;)
    {
        b=b->next;
        a->next=new node(b->item,a);
        a=a->next;
    }
    return *this;
}
int main()
{
    DLL a,b;
    a.InsertAtEnd(89);
    a.InsertAtStart(100);
    b.InsertAtEnd(200);
    b.DelFirst();
    cout<<a;
    
    cout<<b;
    a.DelFirst();
    cout<<endl;
    return 0;
}