#include <iostream>

#include <vector>
#define INF 10000

using namespace std;


vector<vector<int>> floydWarshalAlgo(vector<vector<int>> Graph)
{
    
    vector<vector<int>> dist(Graph);
    
    int Vertices = Graph.size();
    
    for(int k = 0; k < Vertices; k++)
    {
        for(int i = 0; i < Vertices; i++)
        {
            for(int j = 0; j < Vertices; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    
                    dist[i][j] = dist[i][k] + dist[k][j];
                    
                    
                }
            }
                
                
                
        }
        
    }
    
    return dist;
    
}




int main()
{
    vector<vector<int>> Graph = {{0,INF,-2,INF},{4,0,3,INF},{INF,INF,0,2},{INF,-1,INF,0}};
    
    
    
    auto answer = floydWarshalAlgo(Graph);
    
    for(int i = 0; i < Graph.size(); i++)
    {
        for(int j = 0; j < Graph.size(); j++)
        {
            cout << answer[i][j] << "    ";
        }
        
        cout << endl;
    }
    
    

    
    
    
    return 0;
}



