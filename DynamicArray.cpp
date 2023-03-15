#include </home/hp/Softwares/DSA/Array.cpp>
class DynamicArray : public array
{
    private:
        void DoubleCapacity();
        void halfcapacity();

    public:
        DynamicArray()
        {
            
        }
        DynamicArray(int Capacity):array(Capacity)
        {
        }
        void append(int);
        void del(int);
};
void DynamicArray::append(int num)
{
    if (lastindex + 1 == capacity)
        DoubleCapacity();
    lastindex++;
    ptr[lastindex] = num;
}
void DynamicArray::DoubleCapacity()
{
    capacity *= 2;
    int *ptr2 = new int[capacity];
    for (int a = 0; a <= lastindex; a++)
    {
        ptr2[a] = ptr[a];
    }
    delete[] ptr;
    ptr = ptr2;
}
void DynamicArray::del(int index)
{
    if(index<=lastindex&&index>=0)
    {
        for(index;index<lastindex;index++)
        {
            ptr[index]=ptr[index+1];
        }
        lastindex--;
        if(lastindex<=(capacity/2))
        {
            halfcapacity();
        }
    }
    else
        throw *(new IndexOutOfRange());
}
void DynamicArray::halfcapacity()
{
    capacity/=2;
    int *ptr2=new int[capacity];
    for(int a=0;a<=lastindex;a++)
    {
        ptr2[a]=ptr[a];
    }
    delete []ptr;
    ptr=ptr2;
}
int main()
{
    DynamicArray a(9);
    a.append(4);
    a.append(9);
    a.append(10);
    a.append(10);
    a.append(67);
    a.del(2);
    cout<<a[-1]<<endl;
    return 0;
}
