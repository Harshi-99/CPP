#include<iostream>
#include<list>
using namespace std;
class Graph
{
	 int V ;
		list<pair<int,int>> *adj;
 
 public:
        Graph(int V);
        void addEdge(int source, int dest, int cost);
        int minimumDistance(int distance[], bool visited[]);
        void dijkstra(int s);
};
Graph::Graph(int V)
{
     
    this->V = V;
    adj = new list<pair<int,int>>[V];
}
void Graph::addEdge(int source, int dest, int cost)
{
    adj[source].push_back(make_pair(dest,cost));
}
int Graph:: minimumDistance(int distance[], bool visited[])
{
	int min = 999; int index = 0;
	for(int i=0; i<V; i++)
		if(distance[i] <= min && visited[i] == false)
		{
			min = distance[i];
			index = i;
		}
	return index;

}
void Graph::dijkstra(int s)
{
	int distance[V];
	bool *visited = new bool[V];

     for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
	for(int i=0; i<V; i++)
		distance[i] = 999;
	distance[0] = 0;
	for(int i=0; i<V-1; i++){
	int u = minimumDistance(distance, visited);
	visited[u] = true;
	list<pair<int,int>>:: iterator it;
	for(it = adj[u].begin(); it!= adj[u].end(); i++)
		if(visited[it->first]==false && distance[u]!=999 && distance[it->first] > distance[u]+ it->second)
			distance[it->first] = distance[u] + it->second;
	}
	 for(int i = 0; i < V; i++)
    cout<<"0 --> "<<i<<" ---> "<<distance[i]<<endl;

}
	int main()	
	{
    Graph g(5);
    /*g.addEdge(0, 1, 3);
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
   g.addEdge(6, 5, 1);*/
  g.addEdge(0, 1, 2);
  g.addEdge(0, 2, 4);
  g.addEdge(1, 2, 1);
  g.addEdge(1, 3, 4);
  g.addEdge(1, 4, 5);
  g.addEdge(2, 1, 5);
  g.addEdge(2, 3, 2);
  g.addEdge(2, 4, 3);
  g.addEdge(3, 4, 1);
   g.dijkstra(0);
    return 0;
}
