#include "llqueue.cpp"
#include "singlyLinkedList.cpp"
class priorityQueue:public queue
{
    protected:
        SLL priority;
    public:
        priorityQueue(){}
        bool insert(int num);

};
bool priorityQueue::