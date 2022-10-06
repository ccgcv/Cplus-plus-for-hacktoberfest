/* Given a tree, and the cost of a subtree is defined as |S|*AND(S) where |S| is the size of the subtree 
and AND(S) is bitwise AND of all indices of nodes from the subtree, task is to find maximum cost of possible subtree. */


#include <bits/stdc++.h>
using namespace std;

#define N 100010

// Edge structure
struct Edge {
	int u, v;
};

/* v : Adjacency list representation of Graph
	p : stores parents of nodes */
vector<int> v[N];
int p[N];

// Weighted union-find with path compression
struct wunionfind {
	int id[N], sz[N];
	void initial(int n)
	{
		for (int i = 1; i <= n; i++)
			id[i] = i, sz[i] = 1;
	}

	int Root(int idx)
	{
		int i = idx;
		while (i != id[i])
			id[i] = id[id[i]], i = id[i];

		return i;
	}

	void Union(int a, int b)
	{
		int i = Root(a), j = Root(b);
		if (i != j) {
			if (sz[i] >= sz[j]) {
				id[j] = i, sz[i] += sz[j];
				sz[j] = 0;
			}
			else {
				id[i] = j, sz[j] += sz[i];
				sz[i] = 0;
			}
		}
	}
};

wunionfind W;

// DFS is called to generate parent of
// a node from adjacency list representation
void dfs(int u, int parent)
{
	for (int i = 0; i < v[u].size(); i++) {
		int j = v[u][i];
		if (j != parent) {
			p[j] = u;
			dfs(j, u);
		}
	}
}

// Utility function for Union
int UnionUtil(int n)
{
	int ans = 0;

	// Fixed 'i' as AND
	for (int i = 1; i <= n; i++) {
		int maxi = 1;

		// Generating supermasks of 'i'
		for (int x = i; x <= n; x = (i | (x + 1))) {
			int y = p[x];

			// Checking whether p[x] is
			// also a supermask of i.
			if ((y & i) == i) {
				W.Union(x, y);

				// Keep track of maximum
				// size of subtree
				maxi = max(maxi, W.sz[W.Root(x)]);
			}
		}
		
		// Storing maximum cost of
		// subtree with a given AND
		ans = max(ans, maxi * i);
		
		// Separating components which are merged
		// during Union operation for next AND value.
		for (int x = i; x <= n; x = (i | (x + 1))) {
			W.sz[x] = 1;
			W.id[x] = x;
		}
	}
		
	return ans;
}

// Driver code
int main()
{
	int n, i;

	// Number of nodes
	n = 6;

	W.initial(n);

	Edge e[] = { { 1, 2 }, { 2, 3 }, { 3, 4 },
				{ 3, 5 }, { 5, 6 } };

	int q = sizeof(e) / sizeof(e[0]);

	// Taking edges as input and put
	// them in adjacency list representation
	for (i = 0; i < q; i++) {
		int x, y;
		x = e[i].u, y = e[i].v;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	// Initializing parent vertex of '1' as '1'
	p[1] = 1;

	// Call DFS to generate 'p' array
	dfs(1, -1);

	int ans = UnionUtil(n);
		
		printf("Maximum Cost = %d\n", ans);

	return 0;
}


