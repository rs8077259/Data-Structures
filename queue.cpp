#include <iostream>
using namespace std;
class IndexOutOfRange:public exception
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: Index out of range Invalid Index";
        }
};
class CapacityNotSpacified
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: Capacity of the Structure not set";
        }
};
class CapacityFULL
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: Capacity is FULL";
        }
};
class ElementNotSpecified
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: Please Insert Elements before Fetching it";
        }
};
class queue
{
    protected:
        int *ptr=NULL, rear = -1, capacity=0,front=-1;

    public:
        queue()
        {

        }
        queue(int capacity)
        {
            ptr=new int[capacity];
            this->capacity=capacity;
        }
        queue(int capacity,int num)
        {
            ptr=new int[capacity];
            this->capacity=capacity;
            ptr[0]=num;
            front+=1;
            rear+=1;
        }
        void createArray(int);
        bool isEmpty();
        bool insert(int);
        bool overflow();
        bool underflow();
        void delFront();
        int countElements();

        int getrear()
        {
            if(rear+front==-2)
                throw *(new ElementNotSpecified);
            return ptr[rear];
        }
        int getfront()
        {
            if(rear+front==-2)
                throw *(new ElementNotSpecified);
            return ptr[front];
        }
        int getCapacity()
        {
            return capacity;
        }
        ~queue()
        {
            delete []ptr;
        }
};
int queue::countElements()
{
    //has somebugs
    if(rear==-1)
        return 0;
    if(rear+front==0)
        return 1;
    if(rear>front)
        return rear-front+1;
    return (capacity-(front-rear+1));
}
bool queue::underflow()
{
    if(rear+1<capacity||front!=0)
        return true;
    else if(rear+1<front)
        return true;
    return false;
    
}
bool queue::overflow()
{
    if(rear+1==capacity&&front==0)
        return true;
    else if(rear+1==front)
        return true;
    return false;
}
void queue::delFront()
{
    if(front==rear)
        rear=front=-1;
    else{
        if(front+1==capacity)
        {
            if(rear<front)
                front=0;
        }
        else
            front++;
    }
}
void queue::createArray(int size)
{
    delete []ptr;
    ptr = new int[size];
    capacity = size;
}
bool queue::insert(int num)
{
    if(front+rear==-2)
        if(capacity)
        {
            ptr[0]=num;
            front+=1;
            rear++;
            return true;
        }
        else
            throw *(new CapacityNotSpacified);
    else{
        if(rear+1>=capacity)
            if(front==0)
                throw *(new CapacityFULL);
            else{
                ptr[(rear=0)]=num;
                return true;
            }
        if(rear+1==front)
            throw *(new CapacityFULL);
        ptr[++rear]=num;
        return true;
    }
    return false;
}
int main()
{
    queue a(4);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    a.insert(200);
    a.delFront();
    a.insert(90);
    cout<<a.countElements()<<endl;;
    return 0;
}