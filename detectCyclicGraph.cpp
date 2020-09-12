#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int i, bool visited[], bool *recStack);
    public:
        Graph(int V);
        void addEdge(int source, int destination);
        
        bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph:: addEdge(int source, int destination)
{
    adj[source].push_back(destination);
}
bool Graph:: isCyclicUtil(int i, bool visited[], bool *recStack)
{
    if(visited[i] == false)
    {
        visited[i] = true;
        recStack[i] = true;
        list<int> stack;
        list<int> :: iterator it;
        for(it = adj[i].begin(); it!= adj[i].end(); i++)
        {
            if(!visited[*it] && isCyclicUtil(*it, visited, recStack))
            {
                cout<<*it<<" ";
                return true;
            }
            else if(recStack[*it])
                return true;
        }
    }
    recStack[i] = false;
    return false;
}
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i=0; i<V; i++)
        if(isCyclicUtil(i,visited,recStack))
            return true;
        
    return false;
}
int main()
{
    
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);  
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0;
}