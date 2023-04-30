#include "error.cpp"

class AVL
{
    public:
        struct node
        {
            int item,height=1;
            node *right=NULL,*left=NULL;
            node(int item,node *r,node *l):item(item){right=r;left=l;}
            node(int item):item(item){}
        };
    public:
        node * root;
        int incHight(node *ptr,int);
        void preoder(node *);
        void rotate(node *ptr,int);
        void RotateLeft(node *ptr);
        void RotateRight(node*ptr);
        node* findParent(int);
    public:
        AVL();
        AVL(int num);
        ~AVL();
        
        bool insert(int num);
        int height();
        node * find(int);
        bool del(int);
        void print()
        {
            preoder(root);
            cout<<endl;
        }
};
AVL::AVL()
{
    root=NULL;
}
AVL::~AVL()
{
    del(root->item);
}
AVL::AVL(int num)
{
    root=new node(num);
}
void AVL::preoder(AVL::node *a)
{
    if(a)
    {
        cout<<a->item<<',';
        preoder(a->left);
        preoder(a->right);
    }
}
int AVL::incHight(node *ptr,int num)
{
    if(!ptr)
        return 0;
    int h1,h2,h=0;
    h1=incHight(ptr->left,num);
    h2=incHight(ptr->right,num);
    int bf=h1-h2;
    
    if(bf>1||bf<-1)
    {
        rotate(ptr,num);
        h=-1;
    }
    if(h1>=h2)
        return ptr->height=h1+1+h;
    return ptr->height=h2+1+h;
}
bool AVL::insert(int num)
{
    if(!root)
    {
        root=new node(num);
        return true;
    }
    node *ptr=root;
    while(ptr)
    {
        if(num>ptr->item)
        {
            if(ptr->right)
            {
                ptr=ptr->right;
                continue;
            }
            else
            {
                ptr->right=new node(num);
                break;
            }
        }
        else if(num<ptr->item)
        {
            if(ptr->left)
            {
                ptr=ptr->left;
                continue;
            }
            else
            {
                ptr->left=new node(num);
                break;
            }
        }
        else
            throw *(new DuplicateNode);
    }
    
    incHight(root,num);
    return true;
}
int AVL::height()
{
    if(root)
        return root->height;
    return 0;
}
AVL::node* AVL::find(int num)
{
    node *ptr=root;
    while(ptr)
    {
        if (num>ptr->item)
            ptr=ptr->right;
        else if(num<ptr->item)
            ptr=ptr->left;
        else
            return ptr;
    }
    throw *(new NoItem);
}
void AVL::rotate(node *ptr,int num)
{
    if(num>ptr->item)
    {
        if(num>ptr->right->item)
             RotateLeft(ptr);
        else
        {
            RotateRight(ptr->right);
            RotateLeft(ptr);
        }
    }
    if(num<ptr->item)
    {
        if(num<ptr->left->item)
            RotateRight(ptr);
        else{
            RotateLeft(ptr->left);
            RotateRight(ptr);
        }
    }
}
void AVL::RotateLeft(node *ptr)
{
    int num=ptr->item;
    ptr->item=ptr->right->item;
    node *helpp=ptr->right;
    helpp->item=num;
    ptr->right=helpp->right;
    helpp->right=helpp->left;
    helpp->left=ptr->left;
    ptr->left=helpp;
}
void AVL::RotateRight(node *ptr)
{
    int num=ptr->item;
    node *helpn=ptr->left;
    ptr->item=helpn->item;
    ptr->left=helpn->left;
    helpn->item=num;
    helpn->left=helpn->right;
    helpn->right=ptr->right;
    ptr->right=helpn;
}
AVL::node * AVL::findParent(int num)
{
    node * parent=root;
    while(parent)
    {
        if(num > parent->item)
        {
            if(parent->right)
                if(parent->right->item==num)
                    break;
                else
                    parent=parent->right;
        }
        else if(num < parent->item)
        {
            if(parent->left)
                if(parent->left->item==num)
                    break;
                else
                    parent=parent->left;
        }
        else
            break;
        
    }
    return NULL;
}
bool AVL::del(int num)
{
    node *par,*child;
    {
        //determining the parent and child node
        if(root->item==num)
        {
            par=root;
            child=root;
            if(child->left&&child->right)
                goto a;
            else if(child->right)
                root=child->right;
            else if(child->left)
                root=child->left;
            else
                root=NULL;
            return 1;
        }
        else{
            par=findParent(num);
            if(!par)
                return false;
            if(num>par->item)
                child=par->right;
            else
                child=par->left;
        }
    }
    a:
    {
        //Deleting node
        if(child->left==NULL&&child->right==NULL)
        {
            if(num>par->item)
                par->right=NULL;
            else
                par->left=NULL;
            delete child;
            return true;
        }
        else if(child->left&&child->right)
        {
            if(child->right->left==NULL)
            {
                node * c=child->right;
                child->item=child->right->item;
                child->right=child->right->right;
                delete c;
            }
            else
            {
                par=child->right;
                node *c;
                while(par->left->left)
                    par=par->left;
                c=par->left;
                child->item=par->left->item;
                par->left=par->left->right;
                delete c;
            }
        }
        else if(child->left)
        {
            if(par->item<num)
                par->right=child->left;
            else
                par->left=child->left;
            delete child;
        }
        else if(child->right)
        {
            if(par->item<num)
                par->right=child->right;
            else
                par->left=child->right;
            delete child;
        }
        
    }
    return true;

}
int main()
{
    AVL a;
    a.insert(100);
    a.insert(70);
    a.insert(120);
    a.insert(110);
    a.insert(40);
    a.insert(90);
    a.insert(115);
    cout<<a.height();
    return 0;
}