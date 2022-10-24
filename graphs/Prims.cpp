#include <iostream>
#include <vector>
#include <queue> // To set up priority queue
#include <functional> // To use std::greater<T> -> This will prove to be useful in picking the minimum weight
using namespace std;

/* Program that uses Prims Algorithm to generate a Minimum Spanning Tree
 * and hence find the minimum cost to connect all the vertices
 */
 
typedef pair<int, int> Pair; // First = Weight & Second = Vertex
const int Vertices = 4; // 4 vertices (0,1,2,3)
vector <bool> visitedVertex(Vertices, false);

void createEdge(vector <Pair> List[], int u, int w, int v){
  List[u].push_back(make_pair(w, v));
  List[v].push_back(make_pair(w, u)); // do this because undirected graph
} // createAndAddEdge(vector <int> List[], int u, int v, int weight)

void Prims(vector <Pair> List[], int i){
  priority_queue<Pair, vector<Pair>, greater<Pair> > PQ; // Set up priority queue
  Pair info;
  int minCost = 0;
  PQ.push(make_pair(0, i)); // Source has weight 0;
  while (!PQ.empty()){
    info = PQ.top(); // Use to get minimum weight
    i = info.second; // get the vertex
    PQ.pop(); // Pop before checking for cycles
    if (visitedVertex.at(i)) // Check for cycle
      continue; // Already accounted for it, move on
    visitedVertex.at(i) = true; // Else, mark the vertex so that we won't have to visit it again
    cout << "Mark vertex " << info.second << " and add weight " << info.first << endl;
    minCost += info.first; // Add to minCost
    for (vector<Pair>::iterator it = List[i].begin(); it != List[i].end(); it++) // Visit all children
      if (!visitedVertex.at(it->second)) // If vertex hasn't been visited already
        PQ.push(make_pair(it->first, it->second)); // Push vertex and weight onto Priority Queue
  } // While Priority Queue is not empty
   cout << "Minimum cost to connect all vertices : " << minCost << endl;
} // PrimsAlgorithm

int main (void){
  // Idea is to implement the adjacency list as an array of vectors:
  int i = 0;
  vector<Pair> List[numVertices]; // Create an array of vectors that contain pairs of adjacent vertex and weight
  createEdge(List, 0, 1, 1);
  createEdge(List, 0, 2, 3);
  createEdge(List, 1, 4, 2);
  createEdge(List, 1, 3, 3);
  createEdge(List, 2, 5, 3);
  Prims(List, i); // Generate MST and find minCost
  // Minimum Cost should be 7;

} // main()
