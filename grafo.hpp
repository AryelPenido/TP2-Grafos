#ifndef TP2_2___GRAFO_H
#define TP2_2___GRAFO_H

#include <iostream> 
#include <list> 
using namespace std; 

class Grafo 
{ 
  int tam;   
  list<int> *adj;   //lista de adjecencia 
public: 
//contruir grafo
  Grafo(int tamanho); 
  void add(int u, int v);
  void rmv(int u, int v); 
//saber se o grafo é euleriano
    int ePar(int grau[],int  nVertices);
    int eEuleriano(int grau[], int nVertices);
    int eConexo(int grau[],int n);
//imprimir caminho euleriano
  void printEulerTour(); 
  void printEulerUtil(int s);  
  int DFSCont(int v, bool visited[]); 
  bool eValido(int u, int v); 
}; 
#endif