bool isBipartite(vector<vector<int>>& graph) {
    int n= graph.size();
    vector<int> vis(n,0);
    vector<int> q;
    int k, col;
    for (int i=0;i<n;i++){
        if (vis[i]==0){
            vis[i]=1;
            q.clear();
            q.push_back(i);
            while (q.size()>0){
                k=q.back();
                q.pop_back();
                if (vis[k]==1) col=2;
                else col=1;
                for (int j=0; j<graph[k].size();j++){
                    if (vis[graph[k][j]]==0){
                        vis[graph[k][j]]=col;
                        q.push_back(graph[k][j]);
                    }else if (vis[graph[k][j]]!=col) return false;
                }
            }
        }
    }
    return true;
}

// vis -> visited node
// q   -> stack
