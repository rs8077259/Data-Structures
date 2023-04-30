#include</home/hp/Softwares/DSA/error.cpp>
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
        int& operator [](int);
        void operator=(array);
        int greatest();
        int smallest();
        int search(int);
        int sum();
        float avg();
        void rotate();
        void removeDup();
        void swap(int,int);
        friend ostream& operator<<(ostream&,array&);
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
int& array::operator[](int index)
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
int array::greatest()
{
    int a=ptr[0];
    for(int i=1;i<=lastindex;i++)
        if(ptr[i]>a)
            a=ptr[i];
    return a;
}
int array::smallest()
{
    int a=ptr[0];
    for(int i=1;i<=lastindex;i++)
        if(ptr[i]<a)
            a=ptr[i];
    return a;
}
int array::search(int what)
{
    for(int i=0;i<=lastindex;i++)
        if(ptr[i]==what)
            return i;
    return -1;
}
int array::sum()
{
    int s=0,i=0;
    for(i;i<=lastindex;s+=ptr[i],i++);
    return s;
}
float array::avg()
{
    return (sum()/(float)capacity);
}
void array::rotate()
{
    int a=ptr[0];
    for(int i=0;i<=lastindex;ptr[i]=ptr[i+1],i++);
    ptr[lastindex]=a;
}
void array::removeDup()
{
    int j=0;
    for(int i=0;i<=lastindex;i++)
    {
        for(j=i+1;j<=lastindex;j++)
        {
            if(ptr[i]==ptr[j])
                del(j);
        }
    }
}
void array::swap(int e1,int e2)
{
    int a=ptr[e1];
    ptr[e1]=ptr[e2];
    ptr[e2]=a;
}
ostream& operator<<(ostream& cout,array& a)
{
    cout<<'[';
    for(int i=0;i<=a.lastindex;i++)
        cout<<a.ptr[i]<<',';
    cout<<"]\n";
    return cout;
}