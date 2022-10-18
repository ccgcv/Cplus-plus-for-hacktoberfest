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
vector<int> depth;
 
void dfs(int node,int par){
   
    for(auto child : adj[node]){
       if(child != par){
        depth[child] += depth[node] + 1;
        dfs(child, node);
       }
    }

}

void solve(){
   
    int n;
    cin >> n;
    depth.resize(n+1,0);
 
    int u,v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs(1,0);
    int mx_depth = -1,mx_node = 0;
    for(int i = 1; i <= n; i++){
        if(depth[i] > mx_depth){
            mx_depth = depth[i];
            mx_node = i;
        }
        depth[i] = 0;
    } 
    
    dfs(mx_node,0);
    int diameter = -1;
    for(int i = 1; i <= n; i++){
        if(depth[i] > diameter){
            diameter = depth[i];
        }
    }
    
    cout << diameter << '\n';
    
    
     
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    //cin >> tc;
    while(tc--) solve();

}


 