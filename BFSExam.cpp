#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int>*adj;
    public:
        Graph(int V);
        void addEdge(int u, int v);
        void bfs(int source);
}
Graph::Graph(int V)
{
    this->V = V;
    adj = list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void Graph::bfs(int source)
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = 0;
    list<int>queue;
    queue.push_back(source);
    visited[source] = 1;
    while(!queue.empty())
    {
        int x = queue.front();
        queue.pop();
        cout<<x;
        list<int>::iterator it;
        for(it = adj[x].begin(); it!= adj[x].end(); it++)
        {
            if(visited[*it] == 0)
            {
                visited[*it] = 1;
                queue.push_back(*it);
            }
        }
    }
}
void dfsUtil(int i, bool visited[])
{
    visited[i] == true;
    cout<<i;
    list<int>::iterator it;
    for(it = adj[i].begin(); it!=adj[i].end(); it++)
    {
       if(visited[*it] == false)
            dfsUtil(*it, visited);

    }
}
void dfs()
{
    bool visited[] = new bool[V];
    for(int i = 0; i<V; i++)
        visited[i] = false;
    for(int i=0; i<V; i++)
        if(visited[i] == false)
            dfsUtil(i, visited);        
}

void dijkstra(list<pair<int,int>>*adj ,int s)
{
    bool visited[V];
    int distance[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = False;
        distance[i] = INT32_MAX;
        
    }
    distance[s] = 0;
    for(int i=0; i<V; i++)
    {
        int u = min(distance,visited);
        visited[u] = true;
        list<pair<int,int>>::iterator it;
        for(it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(distance[it->first] > distance[u]+it->second && distance[u]!=INT32_MAX && visited[it->first]==false)
                distance[it->first] = distance[u] + it->second;
        }
    }
}
void topologicalSortUtil(int i, bool visited[], list<int>&stack)
{
    visited[i] = true;
    list<int>::iterator it;
    for(it = adj[i].begin(); it!= adj[i].end(); it++)

        if(!visited[*it])
            topologicalSortUtil(*it, visited, stack);
    stack.push(i);    
}
void topologicalSort()
{
    bool *visited = new bool[V];
    list<int>stack[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    for(int i=0; i<V; i++)
        if(visited[i] == false)
            topologicalSortUtil(i, visited, stack);
    while(!stach.empty())
    {
        cout<<stack.top();
        stack.pop();
    }
}