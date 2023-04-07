#include</home/hp/Softwares/DSA/error.cpp>
class CLL
{
    public:
        struct node
        {
            node *next;
            int item;
            node()
            {
                next=NULL;
            }
            node(int item)
            {
                this->item=item;
            }
            node(int item,node * next)
            {
                this->item=item;
                this->next=next;
            }
        };
    private:
        node *last;
    public:
        CLL()
        {
            last=NULL;
        }
        CLL(int);
        CLL(CLL &);
        ~CLL();
        void InsertAtStart(int);
        void InsertAtEnd(int);
        void InsertAfter(int,int);
        int search(int);
        void DelFirst();
        void DelLast();
        void Del(int);
        friend ostream& operator<<(ostream &,CLL );
        

        
};
ostream& operator<<(ostream& cout,CLL obj)
{
    CLL::node * start=obj.last->next;
    cout<<"\n[";
    do
    {
        cout<<start->item<<",";
        start=start->next;
    }
    while(start!=obj.last->next);
    cout<<"]\n";
    return cout;
}
CLL::CLL(int num)
{
    last=new node(num);
    last->next=last;
}
void CLL::InsertAtStart(int num)
{
    if(last)
        last->next=new node(num,last->next);
    else
    {
        last=new node(num);
        last->next=last;
    }
}
void CLL::InsertAtEnd(int num)
{
    if(last)
        {
        last->next=new node(num,last->next);
        last=last->next;
    }
    else
    {
        last=new node(num);
        last->next=last;
    }
    
}
void CLL::DelFirst()
{
    CLL::node *a=last->next;
    last->next=a->next;
    delete a;
}
void CLL::DelLast()
{
    CLL::node *n=last;
    for(;n->next!=last;n=n->next);
    n->next=last->next;
    delete last;
    last=n;
}
void CLL::InsertAfter(int index,int num)

{
    CLL::node *start=last->next;
    if(index==-1)
        InsertAtStart(num);
    else{
        int a=0;
        for(;a!=index && start->next!=last->next;start=start->next,a++);
        if(start->next==last->next)
            InsertAtEnd(num);
        else
            start->next=new node(num,start->next);
    }
}
void CLL::Del(int index)
{
    if(!index)
        DelFirst();
    else{
        CLL::node *start=last->next;
        int a=0;
        index--;
        for(;a!=index&&start->next!=last->next;start=start->next,a++);
        if(start->next==last->next)
            throw *(new IndexOutOfRange);
        else if(start->next==last)
            DelLast();
        else{
            CLL::node *n=start->next;
            start->next=n->next;
            delete n;
        }
    }
}
int CLL::search(int num)
{
    int a=0;
    CLL::node *n=last->next;
    for(;n->item!=num;a++,n=n->next)
        if(n->next==last->next)
            return -1;
    return a;
}
CLL::~CLL()
{
    while(last!=last->next)
        DelFirst();
    delete last;
}
CLL::CLL(CLL &a)
{
    last=NULL;
    CLL::node *n=a.last->next;
    for(;n->next!=a.last->next;n=n->next)
        InsertAtEnd(n->item);
    InsertAtEnd(n->item);
}