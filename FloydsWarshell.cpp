#include<bits/stdc++.h>
#define V 4 
#define INF 99999
using namespace std;
void printSolution(int graph[V][V])
{
        for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
           
            {
                cout<<graph[i][j]<<" ";
            }
        cout<<"\n";
    }   
}
void floydWarshall(int graph[V][V])
{

    for(int k=0; k<4; k++)
    {
        for(int j=0; j<4; j++)
        {
            for(int i=0; i<4; i++)
            {
                if(graph[i][j] > graph[i][k]+graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    printSolution(graph);
}
int main()
{
    
    int graph[4][4] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    }; 
    floydWarshall(graph);
    return 0;
}