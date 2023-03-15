#include</home/hp/Softwares/DSA/queue.cpp>

class deque:public queue
{
public:
    deque(){}
    deque(int capacity):queue(capacity){}
    ~deque(){};
    bool InsertAtFront();
};
bool deque::InsertAtFront()
{
    if(overflow())
        throw *(new CapacityFULL);
    if(!capacity)
        throw *(new CapacityNotSpacified);
    if(rear>front);
    else if(rear=-1);
    
}