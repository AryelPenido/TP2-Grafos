#include<iostream>
#include<stdlib.h>
#include<list>
#include<vector>
#include "grafo.hpp"
int main(){
    using namespace std;
    FILE *arq = NULL;
    char arquivo[30];
    int n, linha,coluna,nlinhas = 1,euleriano = 0;
    cout<<"entre com nome do arquivo: ";
    cin>>arquivo;
    arq = fopen(arquivo,"r");
    if(arq == NULL)
        printf("ERRO ao abrir o arquivo\n");

    fscanf(arq,"%d",&n);
  
    Graph g(n*n);
    int grauVertice[n];
  
    for(int i = 0; i < n; i++){
        grauVertice[i] = 0;
    }
 
    while(!feof(arq)){
        fscanf(arq,"%d %d ",&linha,&coluna);
        grauVertice[linha-1]++;
        grauVertice[coluna-1]++;
        g.addEdge(linha,coluna);
    }
   
 
  euleriano = g.eEuleriano(grauVertice,n,g);
  if(euleriano){
      cout<<"Aqui\n";
      g.printEuler(n,grauVertice);
  }



return 0 ;


}

