#include<iostream>
#include<list>
using namespace std;
# define V 7
int parentArray[V];
class Graph
{
    
    list<int>*cycles;
    list<int>*adj;
    bool isCyclicUtil(int i, bool *visited, int parent);
   
    public:
        Graph();
        void addEdge(int source, int destination);
        void isCycle(int u, int p, int color[], int parent[], int mark[], int &cycleNumber);
        void printCycles(int edge, int mark[], int cycleNumber);
};
Graph::Graph()
{
    
    
    adj = new list<int>[V];
    cycles = new list<int>[V];
}
void Graph:: addEdge(int source, int destination)
{
    adj[source].push_back(destination);
    adj[destination].push_back(source);
}
void Graph::isCycle(int u, int p, int color[], int parent[], int mark[], int &cycleNumber)
{
    if(color[u] == 2)
        return;
    if(color[u] == 1)
    {
        cycleNumber ++;
        int cur = p;
        mark[cur] = cycleNumber;
        while(cur != u)
        {
            cur = parent[cur];
            mark[cur] = cycleNumber;
        }
        return;
    }
    parent[u] = p;
    color[u] = 1;
    for(int v: adj[u])
    {
        
        if(v == parent[u])
            continue;
        isCycle(v,u,color,parent,mark,cycleNumber);
    }

    color[u] = 2;
}
void Graph::printCycles(int edge, int mark[], int cycleNumber)
{
    for(int i=1; i<=edge; i++)
    {
        if(mark[i]!=0)
            cycles[mark[i]].push_back(i);
    }
    for(int i=1; i<=cycleNumber; i++)
    {
        for(int x:cycles[i])
            cout<<x<<" ";
        cout<<"\n";
    }
}

int main()
{
    Graph g1; 
    /*g1.addEdge(1, 2); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 4); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(3, 5); 
    g1.addEdge(7, 8); 
    g1.addEdge(6, 10); 
    g1.addEdge(5, 9); 
    g1.addEdge(10, 11); 
    g1.addEdge(11, 12); 
    g1.addEdge(11, 13); 
    g1.addEdge(12, 13); */
    g1.addEdge(1, 2);
   g1.addEdge(1, 4);
   g1.addEdge(2, 3);
   g1.addEdge(3, 4);
   g1.addEdge(3, 5);
   
    int color[V];
    int parent[V];
    int mark[V];
    int cycleNumber = 0;
    g1.isCycle(1,0,color,parent,mark,cycleNumber);
    g1.printCycles (4, mark, cycleNumber);
    return 0;
}