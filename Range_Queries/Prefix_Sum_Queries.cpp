/*
Hacktoberfest contribution 2022
Prefix Sum Queries
Solution to https://cses.fi/problemset/task/2166
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+10;
int a[maxn], n, m, k, x, t;
pair<int,int> segTree[4*maxn], T;
// Can be done without lazy propagation by walking on the segment tree
pair<int,int> combine(pair<int,int> &left, pair<int,int> &right)
{
    T.first=max(left.first, left.second+right.first);
    T.second=left.second+right.second;
    return T;
}
 
void build(int p=1, int l=0, int r=n-1)
{
	if(l==r) { segTree[p].first=max(0ll, a[l]), segTree[p].second=a[l]; return; }
	int mid = (l+r)/2;
	build(p*2, l, mid);
	build(p*2+1, mid+1, r);
	segTree[p] = combine(segTree[p*2],segTree[p*2+1]);
}
 
void update(int x, int p=1, int l=0, int r=n-1)
{
	if(l==r) { segTree[p].first=max(0ll, a[l]), segTree[p].second=a[l]; return; }
	int mid = (l+r)/2;
	if(x<=mid) update(x, p*2, l, mid);
	else update(x, p*2+1, mid+1, r);
	segTree[p] = combine(segTree[p*2],segTree[p*2+1]);
}
 
pair<int,int> query(int i, int j, int p=1, int l=0, int r=n-1)
{
    if(r<i or l>j or l>r) return {0,0};
	if(l>=i and r<=j) return segTree[p];
	int mid = (l+r)/2;
	auto left = query(i, j, p*2, l, mid);
	auto right = query(i, j, p*2+1, mid+1, r);
	return combine(left, right);
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    build();
    while(m--) {
        cin >> t >> k >> x; k--,x--;
        if(t==1) a[k]=x+1, update(k);
        else cout << query(k,x).first << "\n";
    }
}
