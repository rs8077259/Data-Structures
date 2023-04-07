#include</home/hp/Softwares/DSA/error.cpp>
class DCLL
{
    public:
        struct node
        {
            node *next,*prev=NULL;
            int item;
            node()
            {
                next=NULL;
            }
            node(int item)
            {
                this->item=item;
            }
            node(int item,node * next,node *prev)
            {
                this->item=item;
                this->next=next;
                this->prev=prev;
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
        DCLL()
        {
            last=NULL;
        }
        DCLL(int);
        DCLL(DCLL &);
        ~DCLL();
        void InsertAtStart(int);
        void InsertAtEnd(int);
        void InsertAfter(int,int);
        int search(int);
        void DelFirst();
        void DelLast();
        void Del(int);
        DCLL& operator=(DCLL&);
        friend ostream& operator<<(ostream &,DCLL );        
};
ostream& operator<<(ostream& cout,DCLL obj)
{
    if(obj.last){
        DCLL::node * start=obj.last->next;
        cout<<"[";
        do
        {
            cout<<start->item<<",";
            start=start->next;
        }
        while(start!=obj.last->next);
        cout<<"]\n";
    }
    else
        cout<<"[]\n";
    return cout;
}
DCLL::DCLL(int num)
{
    last=new node(num);
    last->next=last;
    last->prev=last;
}
void DCLL::InsertAtStart(int num)
{
    if(last)
    {
        last->next=new node(num,last->next);
        if(last->prev==last)
        {
            last->prev=last->next;
            last->next->prev=last;
        }
        else
        {
            last->next->next->prev=last->next;
            last->next->prev=last;
        }
    }
    else
    {
        last=new node(num);
        last->next=last;
        last->prev=last;
    }
}
void DCLL::InsertAtEnd(int num)
{
    if(last)
    {
        last->next=new node(num,last->next);
        last->next->prev=last;
        last=last->next;
        if(last->prev==last->prev->prev)
            last->prev->prev=last;
        else
            last->next->prev=last;
        
    }
    else
    {
        last=new node(num);
        last->next=last;
        last->prev=last;
    }
    
}
void DCLL::DelFirst()
{
    if(!last)
        throw *(new NodeNotMade);
    if(last->next==last)
    {
        delete last;
        last=NULL;
    }
    else{
        DCLL::node *a=last->next;
        last->next=a->next;
        a->next->prev=last;
        delete a;
    }
}
void DCLL::DelLast()
{
    if(!last)
        throw *(new NodeNotMade);
    if(last->next==last)
    {
        delete last;
        last=NULL;
    }
    else{
        DCLL::node *n=last->prev;
        n->next=last->next;
        n->next->prev=n;
        delete last;
        last=n;
    }
}
void DCLL::InsertAfter(int index,int num)

{
    DCLL::node *start=last->next;
    if(index==-1)
        InsertAtStart(num);
    else{
        int a=0;
        for(;a!=index && start->next!=last->next;start=start->next,a++);
        if(start->next==last->next)
            InsertAtEnd(num);
        else
            start->next=new node(num,start->next,last);
    }
}
void DCLL::Del(int index)
{
    if(!index)
        DelFirst();
    else{
        DCLL::node *start=last->next;
        int a=0;
        index--;
        for(;a!=index&&start->next!=last->next;start=start->next,a++);
        if(start->next==last->next)
            throw *(new IndexOutOfRange);
        else if(start->next==last)
            DelLast();
        else{
            DCLL::node *n=start->next;
            start->next=n->next;
            delete n;
        }
    }
}
int DCLL::search(int num)
{
    int a=0;
    DCLL::node *n=last->next;
    for(;n->item!=num;a++,n=n->next)
        if(n->next==last->next)
            return -1;
    return a;
}
DCLL::~DCLL()
{
    while(last)
        DelFirst();
    delete last;
}
DCLL::DCLL(DCLL &a)
{
    last=NULL;
    if(a.last)
    {
        DCLL::node *n=a.last->next;
        for(;n->next!=a.last->next;n=n->next)
            InsertAtEnd(n->item);
        InsertAtEnd(n->item);
    }
}
DCLL& DCLL::operator=(DCLL &a)
{
    while(last)
        DelFirst();
    last=NULL;
    if(a.last)
    {
        DCLL::node *n=a.last->next;
        for(;n->next!=a.last->next;n=n->next)
            InsertAtEnd(n->item);
        InsertAtEnd(n->item);
    }
    return a;

}