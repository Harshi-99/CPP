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
		void bfs();

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
void Graph::bfs()
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
	queue.push_back(1);
	visited[1] = true;
    distance[1] = 0;
    list<int>::iterator it;
	while(!queue.empty())
	{
		int x = queue.front();
		queue.pop_front();
		
		for(it = adj[x].begin(); it != adj[x].end(); ++it)
		{
			if(!visited[*it] && *it!=N)
			{
                visited[*it] = true;
				queue.push_back(*it);
                distance[*it] = distance[x] + 1;
				
			}
			
		}
        
	}
      cout<<distance[N-1];

}
int main()
{
	int testCase, N, M, a, b;
    Graph g(6);
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
        g.addEdge(3,4);
        g.addEdge(4,2);
        g.addEdge(4,5);
        g.bfs();
      



	return 0;
}
