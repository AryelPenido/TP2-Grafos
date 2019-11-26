#include<iostream>
#include<stdlib.h>
#include<list>
#include<algorithm>
#include<string.h>
#include "grafo.hpp"

using namespace std;

Grafo::Grafo(int tamanho){
    this->tam = tamanho;
    this->adj = new list<int>[tamanho];
}

 void Grafo::add(int u, int v) {  
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

void Grafo::rmv(int u, int v) 
{
//perccorre lista de adjacencias do vertice u procurando vertice v 
  list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v); 
  *iv = -1; 
  list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u); 
  *iu = -1; 
} 

int Grafo::ePar(int grau[],int  nVertices){
   int cont = 0;
    for(int i = 0; i < nVertices;i++){
        if(grau[i] % 2 == 0)    
            cont++;  
    }
    if(cont == nVertices)
        return 1; 
    else{
        cout<<"Tem vertice de grau impar!\n";
        return 0;
    }
}

int Grafo::eConexo(int grau[],int n){  
bool *visited = new bool[tam];  
  for (int i = 0; i < tam; i++) 
        visited[i] = false; 
  DFSCont(1,visited);
  for(int i=0;i<n;i++){
      if ((!visited[i]) && grau[i] > 0){ 
            return 0;
      }
  }
  return 1;
}

int Grafo:: eEuleriano(int grau[], int nVertices){
    int x, y = 0;
    x = ePar(grau,nVertices);
    if(x){
        y = eConexo(grau,nVertices); 
        if(y){
            cout<<"Eh Euleriano!\n";
            return 1;
        }
        else
        {
            cout << "Nao eh Euleriano!\n";
            return 0;
        }
    }
    else{
        cout << "Nao eh Euleriano!\n";
        return 0;
    }
    
    
   }

int Grafo::DFSCont(int v, bool visited[]){
  visited[v] = true;
  int cont =1;
  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); i++){
    if(!visited[*i])
      cont+=DFSCont(*i, visited);
}
}

void Grafo::printEulerTour()
{ 
//começa sempre do vertice 0,mas pode alterar
  int u = 0;  
  printEulerUtil(u); 
  cout << endl; 
} 
  
void Grafo::printEulerUtil(int u) 
{ 
  list<int>::iterator i; 
  for (i = adj[u].begin(); i != adj[u].end(); ++i) 
  { 
      int v = *i; 
  
      if (v != -1 && eValido(u, v)) 
      { 
          cout << u+1 << "-" << v+1 << "  ";
          rmv(u, v); 
          printEulerUtil(v); 
      } 
  } 
} 
  

bool Grafo::eValido(int u, int v) 
{ 
  
  // Só um vertice adjacente
  int count = 0; 
  list<int>::iterator i; 
  for (i = adj[u].begin(); i != adj[u].end(); ++i){
    if (*i != -1) 
        count++; 
    if (count == 1) 
        return true; 
  } 
     
  
  
  
  // varios vertices, então procurar o que não é ponte
  bool visited[tam]; 
  memset(visited, false, tam); 
  int count1 = DFSCont(u, visited); 

  rmv(u, v); 
  
  memset(visited, false, tam); 
  int count2 = DFSCont(u, visited); 
  add(u, v); 
  return (count1 > count2)? false: true; 
} 
