#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int V;
    list<int>*adj;
    bool isCyclicUtil(int i, bool *visited, int parent);
    public:
        Graph(int V);
        void addEdge(int source, int destination);
        bool isCycle();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph:: addEdge(int source, int destination)
{
    adj[source].push_back(destination);
    adj[destination].push_back(source);
}
bool Graph:: isCyclicUtil(int i, bool *visited, int parent)
{
    visited[i] = true;
    list<int>:: iterator it;
    for(it = adj[i].begin(); it!= adj[i].end(); ++it)
    {
        if(!visited[*it])
        {
            
            if(isCyclicUtil(*it, visited, i)) 
            {
                cout<<*it<<" ";
                return true;
            }
        }
        else if(parent != *it)
        {
            cout<<*it<<" ";
            return true;
        }
        }
    return false;
}
bool Graph:: isCycle()
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    for(int i=0; i<V; i++)
        if(visited[i] != true)
            if(isCyclicUtil(i, visited, -1))
                return true;
        return false;

}
int main()
{
    Graph g1(14); 
    g1.addEdge(1, 2); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 5); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7);
    g1.addEdge(5, 9);
     g1.addEdge(5, 6);
    g1.addEdge(6, 10);
    g1.addEdge(7, 8);
    g1.addEdge(10,11);
    g1.addEdge(11, 12);
    g1.addEdge(12, 13);
    g1.addEdge(13, 11);
    g1.isCycle()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
    return 0;
}