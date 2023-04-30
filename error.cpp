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
class CapacityNotSpacified:public exception
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: Capacity of the Structure not set";
        }
};
class CapacityFULL:public exception
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: Capacity is FULL";
        }
};
class ElementNotSpecified:public exception
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: Please Insert Elements before Fetching it";
        }
};
class NodeNotMade:public exception
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: oo look like you have not initialilasied node please Do it before Deleting it :|";
        }
};
class DuplicateNode:public exception
{
    public:
        const char* what()const throw()
        {
            return "RuntimeError: Trying to insert duplicate value :|";
        }
};
class NoItem:public exception
{
    public:
        const char* what()const throw()
        {
            return "No item specified";
        }
};