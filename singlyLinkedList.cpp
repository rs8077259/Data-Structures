#include <iostream>
using namespace std;

class SLL
{
private:
    struct node
    {
        int item;
        node *next = NULL;
        node()
        {
        }
        node(int num)
        {
            item = num;
        }
        node(int num, node *ptr)
        {
            item = num;
            next = ptr;
        }
    };

    node *start;

public:
    SLL()
    {
        start=NULL;
    }
    SLL(int num)
    {
        start = new node(num);
    }
    SLL(SLL &copy);
    void InsertAtStart(int);
    void InsertAtLast(int);
    void InsertAfter(int, int);
    int count();
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    friend ostream& operator<<(ostream&,SLL);
    ~SLL();
};
ostream& operator<<(ostream& cout,SLL obj)
{
    cout<<'[';
    for(SLL::node *str=obj.start;str;str=str->next)
        cout<<str->item<<',';
    cout<<"\b]";
    return cout;
}
SLL::SLL(SLL &copy)
{
    if(copy.start)
    {
        start=new node(copy.start->item);
        node *ptr=start,*ptr2=copy.start;
        while(ptr2->next)
        {
            ptr2=ptr2->next;
            ptr->next=new node(ptr2->item);
            ptr=ptr->next;
        }
    }
}
void SLL::InsertAtStart(int num)
{
    start = new node(num, start);
}
void SLL::InsertAtLast(int num)
{
    node *ptr = start;
    if (start)
    {
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = new node(num);
    }
    else
    {
        start = new node(num);
    }
}
int SLL::count()
{
    int count = 0;
    if(start)
    {
    node *n = start;
    for (;n->next;count++,n = n->next);
    return ++count;
    }
    return 0;
}
void SLL::InsertAfter(int index, int num)
{
    
    if(start)
    {

        int count=0;
        node *n = start;
        for (;count!=index;count++,n = n->next);
        n->next=new node(num,n->next);
    }
}
void SLL::deleteFirst(){
    if(start)
    {
        node *p=start;
        start=start->next;
        delete p;
    }
}
void SLL::deleteLast()
{
    if(start)
    {
        node *ptr=start,*ptr2;
        while(ptr->next)
        {
            ptr2=ptr;
            ptr=ptr->next;
        }
        delete ptr;
        ptr2->next=NULL;
    }
}
void SLL::deleteNode(int index)
{
    if(start)
    {
        if(index<=0&&index<count())
        {
            int count=0;
            int Count=0;
            node **ptr=&start,*ptr2;
            for(;count!=index;count++)
            {
                ptr=&((**ptr).next);
            }
            ptr2=*ptr;
            *ptr=ptr2->next;
            delete ptr2;
        }
    }
}
SLL::~SLL()
{
    node *ptr;
    while (start)
    {
        ptr=start;
        start=start->next;
        delete ptr;
    }
}

int main()
{
    SLL a;
    a.InsertAtStart(70);
    a.InsertAtLast(19);
    a.InsertAtLast(50);
    a.InsertAfter(3,90);
    cout<<a;
    return 0;
}