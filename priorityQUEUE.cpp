#include "error.cpp"
#include<thread>

class pqueue
{
    private:
        struct node
        {
            node *next;
            int item;
            node(int item,node *next=NULL):item(item),next(next){}
        };
        struct pnode
        {
            int priority;
            pnode *next,*pre;
            node * lastn;
            pnode(int priority,node *lastn=NULL,pnode *next=NULL,pnode *pre=NULL):next(next),pre(pre),lastn(lastn),priority(priority){}
        };
        node *start;
        pnode *pri;
    public:
        pqueue()
        {
            start=NULL;
            pri=NULL;
        }
        pqueue(int item,int priority)
        {
            start=new node(item);
            pri=new pnode(priority,start);
        }
        ~pqueue()
        {
            while (start)
                del();
        }
        void insert(int item,int priority);
        int get();
        void del();        
};
void pqueue::insert(int item,int priority)
{
    if(pri){
    pnode *str=pri;
    for(;str;str=str->next)
    {
        if(!(str->next)&&str->priority>priority)
        {
            str->next=new pnode(priority,str->lastn,NULL,str);
            str=str->next;
        }
        else if(str->priority>priority)
            continue;
        else if(str->priority<priority)
        {
            if(str->pre)
            {
                str->pre->next=new pnode(priority,str->pre->lastn,str,str->pre);
                str->pre=str->pre->next;
                str=str->pre;
            }
            else
            {
                str->pre=new pnode(priority,NULL,str,NULL);
                pri=str->pre;
                pri->lastn=new node(item,start);
                start=pri->lastn;
                break;
            }
        }
        
        str->lastn->next=new node(item,str->lastn->next);
        str->lastn=str->lastn->next;
        break;
    }
    }
    else{
        start=new node(item);
        pri=new pnode(priority,start);
    }
    
}
int pqueue::get()
{
    if(start)
        return start->item;
    else
        throw 1;
}
void pqueue::del()
{
    if(start)
    {
        if(start==pri->lastn)
        {
            if(pri->next)
            {
                pnode *prio=pri;
                pri=pri->next;
                pri->pre=NULL;
                delete prio;
            }
            else{
                delete pri;
                pri=NULL;
            }
        }
        if(start->next)
        {
            node *star=start;
            start=start->next;
            delete star;
        }
        else{
            delete start;
            start=NULL;
        }
    }

}

int main()
{
    pqueue a(20,5);
    a.insert(50,9);
    a.insert(90,8);
    a.insert(6000,9);
    a.del();
    cout<<a.get();
    return 0;
}