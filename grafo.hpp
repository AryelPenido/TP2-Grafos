#ifndef TP2_GRAFOS___GRAFO_H
#define TP2_GRAFOS___GRAFO_H
#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std;

class Graph 
{ 
    int V;    
    list<int>*adj; 
   // int conexo;
    int DFS(int v, bool visited[]); 
public: 
    Graph(int V);  
    int DFS2(int v, bool visited[]); 
    void addEdge(int v, int w); 
    void rmvEdge(int v,int u);
    int ePar(int grau[],int  nVertices);
    int eEuleriano(int grau[], int nVertices,Graph g);
    int eConexo(int grau[],int n);
    void printEuler(int nVertices,int grau[]); 
    void printEulerUtil(int s,int nVertices); 
    bool eValido(int u, int v,int nVertices); 
};
#endif
