#include<iostream>
class Graph
{
    int v;
    int e;
    int **adj;
    public:
        Graph (int v, int e);
        addEdge(int start, int e);
        void dfs(int start, vector <bool>& visited);
};
Graph::Graph(int v, int e)
{
    this->v = v;
    this->e = e;
    adj = new int 
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<e; j++)
        {

        }
    }
}
int main()
{
    int v = 5, e = 4;
    Graph G(v,e);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(0, 4);
    vector <bool> visited (v, false);
    G.dfs(0, visited);

}