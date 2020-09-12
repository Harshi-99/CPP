#include<bits/stdc++.h>
#define V 10000
using namespace std;
class Graph
{
    list<int>*cycles;
    list<pair<int,int>>*adj;
    public:
        Graph();
        void printAllCycles(int u, int p,int color[], int mark[], int parent[], int &cycleNumber);
        void addEdge(int u, int v, int weight);
        void oddSum(int cycleNumber,int edge, int mark[]);
};
Graph::Graph()
{
    
    
    adj = new list<pair<int,int>>[V];
    cycles = new list<int>[V];
}
void Graph:: addEdge(int u, int v, int weight)
{
    adj[u].push_back(make_pair(v,weight));
    adj[v].push_back(make_pair(u,weight));
}
void Graph:: printAllCycles(int u, int p,int color[], int mark[], int parent[], int &cycleNumber)
{int sum = 0;
    if(color[u] == 2)
        return;
    if(color[u] == 1)
    {

        cycleNumber++;
        int cur = p;
        mark[cur] = cycleNumber;
        while(cur != u)
        {
            sum +=
            cur = parent[cur];
            mark[cur] = cycleNumber;
        }
        return;
    }
    parent[u] = p;
    color[u] = 1;
    for(list<pair<int,int>>::iterator it = adj[u].begin(); it!= adj[u].end(); it++)
    {
        
        cout<<"\n";
        if(it->first == parent[u])
            continue;
        printAllCycles(it->first, u,color, mark, parent, cycleNumber) ;
    }

    color[u] = 2;

}
void Graph::oddSum(int cycleNumber,int edge ,int mark[])
{
    int sum = 0;
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
    
    
    
    for (auto i : adj) 
        cout << i.first << "   " << i.second
    
    
cout<<sum;

}

int main()
{
    Graph g;
    g.addEdge(1, 2, 12);
   g.addEdge(1, 4, 20);
   g.addEdge(2, 3, 1);
   g.addEdge(3, 4, 1);
   int edge = 4;
   int color[V],mark[V], parent[V];
   int cycleNumber = 0;
   g.printAllCycles(1,0,color,mark,parent,cycleNumber); 
   g.oddSum(cycleNumber, edge, mark);
    return 0;
}
