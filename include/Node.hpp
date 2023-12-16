#ifndef NO_H
#define NO_H

#include <iostream>

class No{
private:
    int indice;
    int* vizinhos;
    int n_vizinhos=0;
public:

    No(){
        indice=0;
    }

    No(int i, int n){
        indice = i;
        vizinhos = new int[n];
    }
    
    
    void addVizinho(int v){
        if (n_vizinhos >= 0) {
            vizinhos[n_vizinhos] = v;
            n_vizinhos++;
        } else {
            throw std::out_of_range("Índice de vizinho fora do alcance.");
        }
    }

    int GetIndice(){
        return this->indice;
    }

    int* GetVizinhos(){
        return vizinhos;
    }

    int GetNVizinhos(){
        return n_vizinhos;
    }

};

#endif
