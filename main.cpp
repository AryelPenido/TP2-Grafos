#include<iostream>
#include<stdlib.h>
#include<list>
#include<vector>
#include "grafo.hpp"


using namespace std;

int main(){
    
    FILE *arq;
    Grafo *g;
    char arquivo[30];
    int vertices;
    int v1,v2;


    cout<<"entre com nome do arquivo: ";
    cin>>arquivo;
    arq = fopen(arquivo,"r");
    if(arq == NULL)
        printf("ERRO ao abrir o arquivo\n");
    fscanf(arq,"%d",&vertices);
    g = new Grafo(vertices);
    int graus[vertices];
    for(int i = 0; i< vertices;i++){
        graus[i] = 0;
    }
    
   // cout<<"Foi graus";
    while(!feof(arq)){
         fscanf(arq,"%d %d ",&v1,&v2);
         g->add(v1-1,v2-1);
         graus[v1-1]++;
         graus[v2-1]++;
    }
   // int x = g->ePar(graus,vertices);
   int x = g->eEuleriano(graus,vertices);
    if(x){
        g->printEulerTour();
    }

    
    
    
    
    
    
    
    
    return 0;

}