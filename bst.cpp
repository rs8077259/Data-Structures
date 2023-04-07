#include "error.cpp"

class BST
{
    private:
        struct node
        {
            node *left,*right;
            int item;
            node(int num,node *left=NULL,node *right=NULL):item(num),left(left),right(right)
            {}
        };
        node *root;
        void insert(int,node *);
        node * parentNode(int num);
        void preoder(node *a);
        void inoder(node *a);
        void postoder(node *a);
        void copy(node *s);
    public:
        BST():root(NULL){}
        BST(int num)
        {
            root=new node(num);
        }
        bool isEmpty()
        {
            return !root;
        }
        ~BST();
        void insert(int);
        void insertr(int);
        node* search(int);
        bool del(int num);
        friend void print(BST&);
        BST & copy(BST&);
};
void BST::preoder(BST::node *a)
{
    if(a)
    {
        cout<<a->item<<',';
        preoder(a->left);
        preoder(a->right);
    }
}
void BST::postoder(BST::node *a)
{
    if(a)
    {
        postoder(a->left);
        postoder(a->right);
        cout<<a->item<<',';
    }
}
void BST::inoder(BST::node *a)
{
    if(a)
    {
        inoder(a->left);
        cout<<a->item<<',';
        inoder(a->right);
    }
}
void print(BST &obj)
{
    obj.inoder(obj.root);
    cout<<"\n";
}
void BST::insert(int num)
{
    if(isEmpty())
        root=new node(num);
    else
    {
        node *ptr=root;
        while(ptr)
        {
            if (num<ptr->item)
                if(!ptr->left)
                {
                    ptr->left=new node(num);
                    break;
                }
                else
                    ptr=ptr->left;
            else if (num>ptr->item)
                if(!ptr->right)
                {
                    ptr->right=new node(num);
                    break;
                }
                else
                    ptr=ptr->right;
            else
                throw *(new DuplicateNode);
        }
    }

}
void BST::insertr(int num)
{
    if(isEmpty())
        root=new node(num);
    else
        insert(num,root);
}
void BST::insert(int num,node * nod)
{
    if(num>nod->item)
        if(!nod->right)
            nod->right=new node(num);
        else
            insert(num,nod->right);
    else if(num<nod->item)
        if(!nod->left)
            nod->left=new node(num);
        else
            insert(num,nod->left);
    else
        throw *(new DuplicateNode);

}
BST::node* BST::search(int what)
{
    node *ptr=root;
    while(ptr)
        if(what==ptr->item)
            return ptr;
        else if(what>ptr->item)
            ptr=ptr->right;
        else
            ptr=ptr->left;
    return NULL;
}
bool BST::del(int num)
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
            par=parentNode(num);
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
BST::node* BST::parentNode(int num)
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
    return parent;
}
BST::~BST()
{
    while(root)
        del(root->item);
}
BST& BST::copy(BST & obj)
{
    copy(obj.root);
    return *this;
}
void BST::copy(node * s)
{
    if(s)
    {
        insert(s->item);
        copy(s->left);
        copy(s->right);
    }
}