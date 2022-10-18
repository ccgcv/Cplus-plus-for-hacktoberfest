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
const int N = ;

int n,m;
vector<pii> adj[N];
vector<bool> vis;
int d[N]; 

void dijkstra(int src){
    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }
    
    d[src] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq; // {distance, node}
    pq.push({0,src});
    
    while(!pq.empty()){
        auto [dis,node] = pq.top();
        pq.pop();
        
        if(vis[node]) continue;
        vis[node] = true;
        
        for(auto nbr : adj[node]){
            int newdis = dis + nbr.sc;
            int newver = nbr.fr;
            if(newdis < d[newver]){
                d[newver] = newdis;
                pq.push({d[newver],newver});
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
}


void solve(){
   
    cin >> n >> m;
    vis.resize(n+1,0);
    int u,v,w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w}); 
    }
    
    // calling dijkstra for node 1
    int src = 1;
    dijkstra(src);
    
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    //cin >> tc;
    while(tc--) solve();

} 
