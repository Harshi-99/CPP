#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int N;
	list<int>*adj;
	public:
        int *distance;
		Graph(int N);
		void addEdge(int a, int b);
		void bfs(int source, int hops);

};
Graph::Graph(int N)
{
	this->N = N;
    distance = new int[N];
	adj = new list<int>[N];
}
void Graph::addEdge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void Graph::bfs(int source, int hops)
{
    int a = 0;
	int count = 0;
	bool *visited = new bool[N];
	for(int i=1; i<=N; i++)
    {
		visited[i] = false;
        distance[i] = 0;
    }
    list<int>queue;
	queue.push_back(source);
	visited[source] = true;
    distance[source] = 0;
    list<int>::iterator it;
	while(!queue.empty())
	{
		int x = queue.front();
		queue.pop_front();
		
		for(it = adj[x].begin(); it != adj[x].end(); ++it)
		{
			if(!visited[*it])
			{
                visited[*it] = true;
				queue.push_back(*it);
                distance[*it] = distance[x] + 1;
                
				
			}
			
		}
        
        
	}
    for(int i=1; i<N; i++)
    {
        if(distance[i] == hops)
           count ++;
    
    }
    cout<<count;
}
int main()
{
	int testCase, N, M, a, b;
    Graph g(10);
	//cin>>testCase;
	/*for(int i=0; i<testCase; i++)
	{
		cin>>N;
		cin>>M;
		Graph g(N);
		for(int i=0; i<M; i++)
		{
			cin>>a;
			cin>>b;
			g.addEdge(a,b);

		}
		cout<<g.bfs();
	}*/
    
        g.addEdge(1,2);
        g.addEdge(2,3);
        g.addEdge(1,7);
        g.addEdge(2,4);
        g.addEdge(3,4);
        g.addEdge(4,7);
        g.addEdge(7,8);
        g.addEdge(9,7);
        g.addEdge(7,6);
        g.addEdge(5,6);
        g.bfs(2,1);
      



	return 0;
}
