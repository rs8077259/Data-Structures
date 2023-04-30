
#include "error.cpp"
class graph{
    private:
        int v_count,e_count;
        int **adj;
    public:
        ~graph();
        bool CreateGraph(int);
        bool connect(int,int);
        bool connect(int,int,int);
        void printMatrix();
        void printAdjucent(int);
        bool isIsolated(int);
};
bool graph::CreateGraph(int verteces)
{
    v_count=verteces;
    e_count=0;
    adj=new int *[5];
    for(int i=0;i<verteces;i++)
        adj[i]=new int[verteces];
    return true;
}
bool graph::connect(int ver1,int ver2){
    adj[ver1][ver2]=1;
    adj[ver2][ver1]=1;
    return true;
}
bool graph::connect(int ver1,int ver2,int weight)
{
    adj[ver1][ver2]=weight;
    adj[ver2][ver1]=weight;
    return true;
}

void graph::printMatrix()
{
    int j,i;
    if(adj[0])
    {
        for(i=0;i<v_count;i++)
        {
            for(j=0;j<v_count;j++)
                cout<<adj[i][j]<<' ';
            cout<<endl;
        }
    }
}
void graph::printAdjucent(int vertex)
{
    for(int i=0;i<v_count;i++)
        if(adj[vertex][i])
            cout<<i;
    cout<<endl;
}
bool graph::isIsolated(int vertex)
{
    for(int i=0;i<v_count;i++)
        if(adj[vertex][i])
            return 0;
    return 1;
}
graph::~graph()
{
    for(int i=0;i<v_count;i++)
        delete adj[i];
    delete adj;
}
int main()
{
    graph a;
    a.CreateGraph(5);
    a.connect(2,3);
    a.connect(4,2,10);
    a.printMatrix();
    a.printAdjucent(3);
    cout<<a.isIsolated(1);
    return 0;
}
