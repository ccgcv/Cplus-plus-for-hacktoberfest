#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
ll mod = 1e9 +7;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>adj[n];

    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    int sum = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int key[n];
    int parent[n];
    bool mstSet[n];

    for(int i=0;i<n;i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0});   // {key[index], index}

    for(int count = 0; count < n-1 ; count++)
    {
        int u = pq.top().second;
        pq.pop(); 

        mstSet[u] = true;

        for(auto child : adj[u])
        {
            int v = child.first;
            int weight = child.second;

            if(mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                sum += weight;
                pq.push({key[v],v});
                key[v] = weight;
            }
        }
    }

    cout<<sum;

}
