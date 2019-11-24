#include"grafo.hpp"
#include <iostream> 
#include <string.h> 
#include <algorithm> 
#include <list> 
#include<iterator>


using namespace std;

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ adj[v].push_back(w);} 

void Graph::rmvEdge(int v,int u){
  list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v); 
  *iv = -1; 
  list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u); 
  *iu = -1; 
   
}
   

int Graph::DFS(int v, bool visited[]) 
{
    int cont =1;
    visited[v-1] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
           cont += DFS(*i, visited); 
    return cont;
} 
  
int Graph::DFS2(int v, bool visited[]) 
{ 
  int cont =1;
 // cout<< v;
    visited[v-1] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
           cont += DFS2(*i, visited); 
    return cont;
} 

int Graph::ePar(int grau[],int  nVertices){
    int cont = 0;
    for(int i = 0; i < nVertices;i++){
        if(grau[i] % 2 == 0)    
            cont++;  
    }
    if(cont == nVertices)
        return 1; 
    else{
        cout<<"Tem vertice de grau impar\n";
        return 0;
    }
}


int Graph::eConexo(int grau[],int n){  
bool *visited = new bool[V];  
  for (int i = 0; i < V; i++) 
        visited[i] = false; 
  DFS(1,visited);
  for(int i=0;i<n;i++){
      if ((!visited[i]) && grau[i] > 0){ 
            return 0;
      }
  }
  return 1;
}


int Graph:: eEuleriano(int grau[], int nVertices,Graph g){
    int x, y = 0;
    x = ePar(grau,nVertices);
    if(x){
        y = eConexo(grau,nVertices); 
        if(y){
            cout<<"É Euleriano\n";
            return 1;
        }
        else
        {
            cout << "não é Euleriano\n";
            return 0;
        }
    }
    else{
        cout << "não é Euleriano\n";
        return 0;
    }
    
    
   } 
   





void Graph::printEuler(int nVertices,int grau[]) 
{ 
  
  int u =1; 
  printEulerUtil(u,nVertices); 
  cout << endl; 
} 
  
// Print Euler tour starting from vertex u 
void Graph::printEulerUtil(int u,int nVertices) 
{ 
   // cout<<"u: "<<u<<"\n";
  // Recur for all the vertices adjacent to this vertex 
  list<int>::iterator i; 
 // cout<<i.;
 //cout<<*i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i) 
  { 
     // cout<<"dentro do for\n";
      int v = *i; 
    //  cout<<"v: "<<v<<"\n";
  
      // If edge u-v is not removed and it's a a valid next edge 
      if (v != -1 && eValido(u, v,nVertices)) 
      {
          //cout<<"dentro do if\n"; 
          cout << u << "-" << v << "  "; 
          rmvEdge(u, v); 
          printEulerUtil(v,nVertices); 
      } 
  } 
} 
  


bool Graph::eValido(int u, int v,int nVertices) 
{ 
    //cout<<"Dentro do eValido\n";
  // The edge u-v is valid in one of the following two cases: 
  
  // 1) If v is the only adjacent vertex of u 
  int count = 0;  // To store count of adjacent vertices 
  list<int>::iterator i; 
  for (i = adj[u].begin(); i != adj[u].end(); ++i){
     // cout<<"dentro desse for\n";
    if (*i != -1) 
        count++; 
    if (count == 1) 
        return true; 
  
  }
    
  
  // 2) If there are multiple adjacents, then u-v is not a bridge 
  // Do following steps to check if u-v is a bridge 
  
  // 2.a) count of vertices reachable from u 
  bool visited[nVertices]; 
  memset(visited, false, nVertices); 
  int count1 = DFS2(u, visited); 
  
  // 2.b) Remove edge (u, v) and after removing the edge, count 
  // vertices reachable from u 
  rmvEdge(u, v); 
  memset(visited, false, nVertices); 
  int count2 = DFS2(2u, visited); 
  
  // 2.c) Add the edge back to the graph 
  addEdge(u, v); 
  
  // 2.d) If count1 is greater, then edge (u, v) is a bridge 
  if(count1 > count2){
      return false;
  }
  else{
      return true;
  }
} 

