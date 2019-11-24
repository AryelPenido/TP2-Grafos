#ifndef TP2_GRAFOS___ALGORITMO_H
#define TP2_GRAFOS___ALGORITMO_H


  void printEulerTour(Graph g); 
  void printEulerUtil(int s); 
  
  // This function returns count of vertices reachable from v. It does DFS 
  int DFSCount(int v, bool visited[]); 
  
  // Utility function to check if edge u-v is a valid next edge in 
  // Eulerian trail or circuit 
  bool isValidNextEdge(int u, int v); 
 
#endif