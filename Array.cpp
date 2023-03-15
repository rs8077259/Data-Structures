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
class array
{
    protected:
        int *ptr=NULL, lastindex = -1, capacity=0;

    public:
        array()
        {

        }
        array(int capacity)
        {
            ptr=new int[capacity];
            this->capacity=capacity;
        }
        void createArray(int);
        bool isEmpty();
        bool insert(int, int);
        void append(int);
        void edit(int,int);
        void del(int);
        int get(int);
        bool isFull();
        int getIndex(int);
        int operator [](unsigned int);
        int operator [](signed int);
        void operator=(array);
        int count()
        {
            return lastindex+1;
        }
        int getLastIndex()
        {
            return lastindex;
        }
        int getCapacity()
        {
            return capacity;
        }
        ~array()
        {
            delete ptr;
        }
};
int array::getIndex(int element)
{
    for(int a=0;a<=lastindex;a++)
    {
        if(ptr[a]==element)
            return a;
    }
    return -1;
}
bool array::isFull()
{
    return lastindex==capacity-1?true:false ;
}
void array::append(int value)
{
    if(!ptr)
        throw *(new CapacityNotSpacified);
    if(lastindex<capacity-1)
    {
        lastindex++;
        ptr[lastindex]=value;  
    }
    else{
        throw *(new IndexOutOfRange);
    }
}
void array::createArray(int size)
{
    delete []ptr;
    ptr = new int[size];
    capacity = size;
}
bool array::isEmpty()
{
    if (lastindex == -1)
        return true;
    return false;
}
bool array::insert(int index, int value)
{
    if (index <= lastindex)
        if (lastindex + 1 < capacity-1)
        {
            
            insert(index + 1, ptr[index]);
            ptr[index] = value;
            return true;
        }
    if(lastindex+1==index)
    {
        lastindex++;
        ptr[lastindex]=ptr[index];
        ptr[index]=value;
        return true;
    }
    return false;     
}
void array::edit(int index,int value)
{
    if(index<=lastindex)
    {
        ptr[index]=value;
    }
}
void array::del(int index)
{
    if(index<lastindex)
    {
        ptr[index]=ptr[index+1];
        del(index+1);
    }
    else if(index==lastindex)
    {
        lastindex--;
    }
}
int array::get(int index)
{
    if(index<=lastindex)
        return ptr[index];
    throw *(new IndexOutOfRange);
}
int array::operator[](int index)
{
    if(index>=0)
    {
        if(index<=lastindex)
            return ptr[index];
        throw *(new IndexOutOfRange);
    }
    else{
    index+=1;
    index=lastindex+index;
    if(index<0)
        throw *(new IndexOutOfRange);
    return this->operator[](index);
    }

}
void array::operator=(array arr)
{
    
}