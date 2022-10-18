//  ।।जय माता दी।।  

#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
        #include "debug.hpp"
    #else
        #define debug(...)
#endif
 
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define rall(x)            (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define per(i,a,b)        for(int i=a;i>=b;i--)
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7; 
const int N = 1e5;

vector<int> adj[N];
vector<int> color;

bool dfs(int node, int par, int col){
    
    // arriving the node
    color[node] = col;
    bool isBiPartite = true; // assuming the graph is bipartite 
    
    
    // doing some operations on node 
    for(auto child : adj[node]){
        
        if(child != par && col == color[child]) return false;  // if alternate node with same color is found 
        
        if(color[child] == 0)
         isBiPartite |= dfs(child, node, 3 - col);   
    }
    
    // returning from node
    return isBiPartite;
}

void solve(){
   
    int n,m;
    cin >> n >> m;
    color.resize(n+1,0);
    int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].pb(v);
    }
    
    bool isBiPartite = false;
    
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            isBiPartite |= dfs(i,-1,1);
        }
    }
    
    dbg(color);
    if(isBiPartite){
        cout << "YES Graph is BiPartite\n";
    }
    else{
        cout << "Graph is not Bipartite\n";
    }
      
     
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    //cin >> tc;
    while(tc--) solve();

} 
