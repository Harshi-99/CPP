#include<iostream>
#include<list>
#include<set>
#include<algorithm>
class Graph
{
    int V;
    list<pair<int,int>>*adj;
    public:
        int dest;
        int cost;
        Graph(int V);
        void addEdge(int source,int dest, int cost);
        int min_distance(int distance[], bool visited[]);
        void dijkstra(list<pair<int,int>>*adj, int s);
}
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int,int>>[V];
}
void Graph::addEdge(int source, int dest, int cost)
{
    adj[source].push_back(make_pair(dest,cost));
}
int Graph:: min_distance(int dist[], bool visited[]){
  int Min = INT_MAX, index = 0;
  for(int i = 0; i < 5; i++)
    if(dist[i] <= Min && visited[i] == false){
      Min = dist[i];
      index = i;
    }
  return index;
}

void Graph::dijkstra(list<pair<int,int>>*adj, int s)
{
    int distance[V];
    bool visited[V];
     for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    for(int i=0; i<V; i++)
        distance[i] = INT_MAX;
    distance[0] = 0;
    for(int i=0; i<V; i++)
    {
        int u = min_distance(distance,visited);
        visited[u] = true;
        for(list<pair<int,int>>:: iterator it = adj[u].begin(); it !=  adj[u].end(); it++)
            if(visited[it->first] == false && distance[u] != INT_MAX && distance[it->first] > distance[u] + it->second)
                distance[it->first] = distance[u] + it->second;

    }
}
int main()
{
    Graph g(7);
    g.addEdge(0, 1, 3);
   g.addEdge(0, 2, 6);
   g.addEdge(1, 0, 3);
   g.addEdge(1, 2, 2);
   g.addEdge(1, 3, 1);
   g.addEdge(2, 1, 6);
   g.addEdge(2, 1, 2);
   g.addEdge(2, 3, 1);
   g.addEdge(2, 4, 4);

   g.addEdge(2, 5, 2);
   g.addEdge(3, 1, 1);
   g.addEdge(3, 2, 1);
   g.addEdge(3, 4, 2);
   g.addEdge(3, 6, 4);
   g.addEdge(4, 2, 4);
   g.addEdge(4, 3, 2);
   g.addEdge(4, 5, 2);
   g.addEdge(4, 6, 1);
   g.addEdge(5, 2, 2);
   g.addEdge(5, 4, 2);
   g.addEdge(5, 6, 1);
   g.addEdge(6, 3, 4);
   g.addEdge(6, 4, 1);
   g.addEdge(6, 5, 1);
   g.dijkstra(adj, 0);
    return 0;
}