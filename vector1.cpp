#include<iostream>
#include<list>
using namespace std;
class Graph()
{
    int V;
    list<pair<int,int>> *adj;
    public:
        Graph(int V);
        void addEdge(int source, int dest, int cost);
        int minimumDistance(int distance[], bool visited);
        void dijkstra(list<pair<int,int>> *adj, int s);
}
Graph::Graph(int V)
{
    
    this->V = V;
    
}

void Graph::addEdge(int source, int dest, int cost)
{
    
    adj[source].push_back(make_pair(dest, cost));
}
void dijkstra(list<pair<int,int>> *adj, int s);
int main()
{
    

    
    
    return 0;
}




/*
    string s;
    vector<string>g;
    for(int i=0; i<5; i++)
        cin>>s;
        g.push_back(s);

g.push_back('a');
    g.push_back('b');
    g.push_back('c');
    g.push_back('d');
    g.push_back('e');
    
    for(auto i=g.begin(); i!=g.end(); i++)
        cout<<*i;
        cout<<"\n";
    for(auto i=g.rbegin(); i!=g.rend(); i++)
        cout<<*i;
        cout<<"\n";
    for(auto i=g.cbegin(); i!=g.cend(); i++)
        cout<<*i;
        cout<<"\n";
    for(auto i=g.crbegin(); i!=g.crend(); i++)
        cout<<*i;
        cout<<"\n";
    cout<<g.size()<<"\n";
    cout<<g.capacity()<<"\n";
    cout<<g.max_size()<<"\n";
    g.resize(3);
    cout<<g.size();
    if(g.empty() == false)
        cout<<"empty";
    else
       cout<<"not empty";
    g.shrink_to_fit();
    auto i = g.begin();
        cout<<type_id(*i);*/
        