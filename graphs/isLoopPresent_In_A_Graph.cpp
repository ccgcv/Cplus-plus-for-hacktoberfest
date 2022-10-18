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
vector<int> visited;

bool dfs(int node,int par){
    
    visited[node] = true;
    bool isLoopPresent = false;
    
    for(auto child : adj[node]){
        
        if(visited[child] && child == par) continue;
        if(visited[child]) return true;
        
        isLoopPresent |= dfs(child, node);   
    }
    
    return isLoopPresent;
}

void solve(){
   
    int n,m;
    cin >> n >> m;
    visited.resize(n+1);
    int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    bool isLoopPresent = false;
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            isLoopPresent |= dfs(i,-1);
        }
    }
    
    if(isLoopPresent){
        cout << "YES LOOP IS PRESENT\n";
    }
    else{
        cout << "NO\n";
    }
      
     
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    //cin >> tc;
    while(tc--) solve();

}


 