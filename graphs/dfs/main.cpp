#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int,bool>visited;

void dfs(vector<int>graph[],int vertex){
    if(visited[vertex])return;
    visited[vertex]=true;
    cout<<vertex<<" ";
    for(int child: graph[vertex]){
        dfs(graph,child);
    }
}

int main(){
    int n=6,m=8;
    vector<int>graph[n];
    graph[0].push_back(4);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[1].push_back(5);
    graph[2].push_back(1);
    graph[2].push_back(0);
    graph[2].push_back(4);
    graph[2].push_back(3);
    graph[2].push_back(5);
    graph[3].push_back(2);
    graph[3].push_back(5);
    graph[4].push_back(2);
    graph[4].push_back(5);
    graph[5].push_back(1);
    graph[5].push_back(2);
    graph[5].push_back(3);
    graph[5].push_back(4);
    dfs(graph,0);
    return 0;
}
