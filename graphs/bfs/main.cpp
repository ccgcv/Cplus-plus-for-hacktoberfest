#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

queue<int>q;
unordered_map<int,bool>visited;


void bfs(vector<int>graph[],int n){
    for(int i=0;i<=n;i++){
        if(!visited[i]){
            q.push(i);
            while(!q.empty()){
                if(!visited[q.front()]){
                    cout<<q.front()<<" ";
                    visited[q.front()] = true;
                    for(auto it:graph[q.front()]){
                        q.push(it);
                    }
                }
                q.pop();
            }
        }
    }
}

int main(){
    vector<int>graph[7];
    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(6);
    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(2);
    graph[4].push_back(6);
    graph[5].push_back(3);
    graph[6].push_back(1);
    graph[6].push_back(4);
    bfs(graph,6);
    return 0;
}
